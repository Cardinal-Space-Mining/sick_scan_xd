REM 
REM Run a basic sick_generic_caller unittest on Windows 64 (standalone, no ROS required) with a test server emulating a basic picoscan (timtwo) device
REM 

rem set PATH=%ProgramFiles(x86)%\Microsoft Visual Studio\Shared\Python36_64;%ProgramFiles(x86)%\Microsoft Visual Studio\Shared\Python37_64;%PATH%
rem set PATH=c:\vcpkg\installed\x64-windows\bin;%PATH%

REM 
REM Start sopas test server
REM 

pushd ..\..\build_win64
python --version
start "python multiscan_sopas_test_server.py" cmd /k python ../test/python/multiscan_sopas_test_server.py --tcp_port=2111 --cola_binary=0 --FREchoFilter=1
@timeout /t 3

REM 
REM Start sick_generic_caller
REM 

start "sick_generic_caller" cmd /k .\Debug\sick_generic_caller.exe ../launch/sick_picoscan.launch hostname:=127.0.0.1 udp_receiver_ip:=127.0.0.1
@timeout /t 3

REM 
REM Run pcapng player
REM 

@echo.
@echo Playing pcapng-files to emulate picoscan (timtwo). Note: Start of UDP msgpacks in 20221010_timtwo.pcapng takes a while...
@echo.
python ../test/python/multiscan_pcap_player.py --pcap_filename=../test/emulator/scandata/20230315-picoscan.pcapng --udp_port=2115
python ../test/python/multiscan_pcap_player.py --pcap_filename=../test/emulator/scandata/20221010_timtwo.pcapng --udp_port=2115

popd
@pause
