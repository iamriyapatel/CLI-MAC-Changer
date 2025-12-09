# **CLI MAC Address Changer (C++)**

A small command-line tool written in C++ to change the MAC address of a network interface on Linux.
This was built to understand how MAC spoofing works in real systems and how network identification can be altered or monitored for security purposes.

---

## **Features**

* Change MAC address of any network interface
* Accepts interface + new MAC as user input
* Basic MAC format validation
* Uses Linux networking commands internally
* Quick to compile and run from the terminal

---

## **Why This Project**

I built this to learn:

* How MAC spoofing works in offensive and defensive security
* How Linux handles network interfaces at a low level
* How attackers modify MACs to bypass filters or tracking
* How to build small security utilities in C++

---

## **Usage**

Compile:

```
g++ mac_changer.cpp -o mac_changer
```

Run:

```
sudo ./mac_changer <interface> <new-mac>
```

Example:

```
sudo ./mac_changer wlan0 00:11:22:33:44:55
```

Verify:

```
ifconfig wlan0
```

or

```
ip link show wlan0
```

---

## **Requirements**

* Linux system
* g++ installed
* Root privileges for MAC changes

---

## **Tech Stack**

* C++
* Linux Networking Commands
* system() calls
