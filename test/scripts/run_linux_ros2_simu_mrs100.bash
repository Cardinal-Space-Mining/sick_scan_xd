#!/bin/bash

# killall and cleanup after exit
function killall_cleanup()
{
  sleep 1 ; killall -SIGINT rviz2
  sleep 1 ; killall -SIGINT sick_generic_caller
  sleep 1 ; pkill -f mrs100_sopas_test_server.py
  sleep 1 ; killall -9 rviz2
  sleep 1 ; killall -9 sick_generic_caller
}

# Run example ros service calls
function call_service_examples()
{
  sleep 0.1 ; ros2 service list
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sMN IsSystemReady'}"                             # response: "sAN IsSystemReady 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sMN SetAccessMode 3 F4724744'}"                  # response: "sAN SetAccessMode 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN ScanDataEthSettings 1 +127 +0 +0 +1 +2115'}" # response: "sWA ScanDataEthSettings"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN ScanDataFormat 1'}"                          # response: "sWA ScanDataFormat"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN ScanDataPreformatting 1'}"                   # response: "sWA ScanDataPreformatting"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN ScanDataEnable 1'}"                          # response: "sWA ScanDataEnable"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sMN LMCstartmeas'}"                              # response: "sAN LMCstartmeas"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sMN Run'}"                                       # response: "sAN Run 1"
}  

# Run example ros service calls for filter settings
function call_service_filter_examples()
{
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sRN FREchoFilter'}"                                                # response: "sRA FREchoFilter 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sRN LFPangleRangeFilter'}"                                         # response: "sRA LFPangleRangeFilter 0 C0490FF9 40490FF9 BFC90FF9 3FC90FF9 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sRN LFPlayerFilter'}"                                              # response: "sRA LFPlayerFilter 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sMN SetAccessMode 3 F4724744'}"                                    # response: "sAN SetAccessMode 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN FREchoFilter 1'}"                                              # response: "sWA FREchoFilter"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN LFPangleRangeFilter 0 C0490FF9 40490FF9 BFC90FF9 3FC90FF9 1'}" # response: "sWA LFPangleRangeFilter"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sWN LFPlayerFilter 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1'}"            # response: "sWA LFPlayerFilter"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sMN Run'}"                                                         # response: "sAN Run 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sRN FREchoFilter'}"                                                # response: "sRA FREchoFilter 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sRN LFPangleRangeFilter'}"                                         # response: "sRA LFPangleRangeFilter 0 C0490FF9 40490FF9 BFC90FF9 3FC90FF9 1"
  sleep 0.1 ; ros2 service call /ColaMsg sick_scan/srv/ColaMsgSrv "{request: 'sRN LFPlayerFilter'}"                                              # response: "sRA LFPlayerFilter 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"
}  

# 
# Run sick_scansegment_xd on ROS2-Linux
# 

pushd ../../../..
printf "\033c"
if [ -f /opt/ros/eloquent/setup.bash ] ; then source /opt/ros/eloquent/setup.bash ; fi
if [ -f /opt/ros/foxy/setup.bash     ] ; then source /opt/ros/foxy/setup.bash     ; fi
source ./install/setup.bash
killall_cleanup
sleep 1
rm -rf ~/.ros/log
sleep 1

# Run mrs100 emulator (sopas test server)
python3 ./src/sick_scan_xd/test/python/mrs100_sopas_test_server.py --tcp_port=2111 --cola_binary=0 &
ros2 run rviz2 rviz2 -d ./src/sick_scan_xd/test/emulator/config/rviz2_cfg_mrs100_emu.rviz & 
sleep 1
ros2 run rviz2 rviz2 -d ./src/sick_scan_xd/test/emulator/config/rviz2_cfg_mrs100_emu_360.rviz & 
sleep 1

# Start sick_generic_caller with sick_scansegment_xd
echo -e "run_lidar3d.bash: sick_scan sick_scansegment_xd.launch.py ..."
ros2 launch sick_scan sick_scansegment_xd.launch.py hostname:=127.0.0.1 udp_receiver_ip:="127.0.0.1" &
sleep 3 # read -p "Press ENTER to continue..."

# Run example ros service calls
call_service_examples
call_service_filter_examples
sleep 3

# Play pcapng-files to emulate MRS100 output
echo -e "\nPlaying pcapng-files to emulate MRS100. Note: Start of UDP msgpacks in 20220915_mrs100_msgpack_output.pcapng takes a while...\n"
python3 ./src/sick_scan_xd/test/python/mrs100_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20220915_mrs100_msgpack_output.pcapng --udp_port=2115 --repeat=2
python3 ./src/sick_scan_xd/test/python/mrs100_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20210929_mrs100_token_udp.pcapng --udp_port=2115 --repeat=2
python3 ./src/sick_scan_xd/test/python/mrs100_pcap_player.py --pcap_filename=./src/sick_scan_xd/test/emulator/scandata/20210929_mrs100_cola-a-start-stop-scandata-output.pcapng --udp_port=2115
sleep 3

# Shutdown
echo -e "run_lidar3d.bash finished, killing all processes ..."
killall_cleanup
popd
