# **MAC Changer CLI**  
A command-line tool to change and spoof MAC addresses with vendor identification.  

## **Features**  
✅ Random MAC address generation  
✅ Vendor lookup from OUI list  
✅ Secure and privacy-focused  

## **Usage**  
Run the following command:  
```sh
sudo ./mac_changer <network-interface> [optional-new-MAC]
```
- **`<network-interface>`** → Specify the network interface (e.g., `eth0`, `wlan0`).  
- **`[optional-new-MAC]`** → Provide a custom MAC address (optional). If not specified, a random MAC is generated.  

## **Example Commands**  
**Change MAC randomly:**  
```sh
sudo ./mac_changer eth0
```
**Set a specific MAC address:**  
```sh
sudo ./mac_changer eth0 00:1A:2B:3C:4D:5E
```

## **Installation & Compilation**  
Compile the program using:  
```sh
g++ mac_changer.cpp -o mac_changer
```
