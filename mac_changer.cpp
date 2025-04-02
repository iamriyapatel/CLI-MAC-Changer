#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

map<string, string> loadOUIList(const string &filename) {
    map<string, string> ouiMap;
    ifstream file(filename);
    string line, oui, vendor;
    
    while (getline(file, line)) {
        if (line.size() < 8 || line[2] != '-' || line[5] != '-') continue;
        oui = line.substr(0, 8);
        vendor = line.substr(9);
        ouiMap[oui] = vendor;
    }
    
    return ouiMap;
}

string generateRandomMAC() {
    string mac = "02"; 
    for (int i = 0; i < 5; ++i) {
        int byte = rand() % 256;
        stringstream ss;
        ss << hex << (byte < 16 ? "0" : "") << byte;
        mac += ":" + ss.str();
    }
    return mac;
}

void changeMAC(const string &interface, const string &newMAC) {
    string cmd = "sudo ifconfig " + interface + " down";
    system(cmd.c_str());
    cmd = "sudo ifconfig " + interface + " hw ether " + newMAC;
    system(cmd.c_str());
    cmd = "sudo ifconfig " + interface + " up";
    system(cmd.c_str());
}

string getCurrentMAC(const string &interface) {
    string cmd = "cat /sys/class/net/" + interface + "/address";
    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) return "";
    char buffer[18];
    fgets(buffer, 18, pipe);
    pclose(pipe);
    return string(buffer);
}

string getVendor(const string &mac, const map<string, string> &ouiMap) {
    string oui = mac.substr(0, 8);
    if (ouiMap.find(oui) != ouiMap.end()) {
        return ouiMap.at(oui);
    }
    return "Unknown Vendor";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <network-interface> [new-MAC]" << endl;
        return 1;
    }
    
    string interface = argv[1];
    string newMAC = (argc == 3) ? argv[2] : generateRandomMAC();
    
    cout << "Changing MAC address of " << interface << " to " << newMAC << "..." << endl;
    changeMAC(interface, newMAC);
    
    string currentMAC = getCurrentMAC(interface);
    cout << "New MAC Address: " << currentMAC << endl;
    
    map<string, string> ouiMap = loadOUIList("oui.txt");
    cout << "Vendor: " << getVendor(currentMAC, ouiMap) << endl;
    
    return 0;
}
