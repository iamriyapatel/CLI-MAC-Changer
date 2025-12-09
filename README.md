# **CLI MAC Address Changer (C++)**

A simple command-line tool that lets you change the MAC address of a network interface on Linux.
It was built to understand how MAC spoofing works, how attackers use it for evasion, and how defenders can detect unauthorized changes.

---

## **Features**

* Change the MAC address of any network interface
* Validates MAC format and user input
* Verifies if the MAC update was applied
* Uses Linux networking commands through C++
* Beginner-friendly security utility

---

## **Why I Built This**

This project helped me learn:

* How MAC spoofing works in real environments
* How network interfaces are configured in Linux
* How attackers modify MACs to bypass filters
* How defenders detect and prevent spoofing attempts
* Writing small security tools in C++

---

## **How to Use**

Compile:

```
g++ mac_changer.cpp -o mac_changer
```

Run:

```
sudo ./mac_changer --interface wlan0 --new-mac 00:11:22:33:44:55
```

Verify:

```
ifconfig wlan0
```

---

## **Tech Stack**

* C++
* Linux Networking Commands
* system() calls for command execution
