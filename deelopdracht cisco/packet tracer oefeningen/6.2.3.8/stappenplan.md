#Lab 2.3.2.3: Configuring Rapid PVST+, PortFast, and BPDU Guard

###Required Resources
1. 3 Routers (Cisco 1941 with Cisco IOS Release 15.2(4)M3 universal image or comparable)
2.  Console cables to configure the Cisco IOS devices via the console ports 
3.  Serial cables as shown in the topology


## Part 1: Build the Network and Configure Basic Device Settings ##

######Step 1

Additional info for Cisco Packet Tracer: The 1941 routers don't come with default serial ports. These modules have to be added by clicking on the router and, in the `physical`-pane, turn the router off and adding the `HWIC-2T` module.

For the serial connections you have to make sure that the DCE part of the cable is plugged into the right device(see ip addressing table).

#######Step 3

The first few steps are the same in every router.

1. en
2. conf t
3. no ip domain-lookup
4. hostname R1
5. enable secret class
6. line con 0
7. password cisco
8. login
9. logging synchronous
10. line vty 0 4
11. password cisco
12. login
13. exit
14. banner motd "Unauthorized access is prohibited"

Now we have to configure the ip addresses of the serial ports and the loopback addresses.
In this example we'll use router 1, although these commands are mostly the same for the other devices.
S0/0/0 is the DCE side of the serial connection so we also have to change the clock rate. In the other routers, if those ports aren't the DCE side, simply ignore the clock rate command.

1. r1(config)#: int lo0
2. ip address 209.165.200.225 255.255.255.252
3. int lo1 
4. ip address 192.168.1.1 255.255.255.0
5. int lo2
6. ip address 192.168.2.1 255.255.255.0
7. int s0/0/0
8. ip address 192.168.12.1 255.255.255.0
9. no sh
10. bandwidth 128
11. clock rate 128000
12. end
13. copy running-config startup-config 
