#include<iostream>
#include<string.h>
#include<random>
#include<ctime>
using namespace std;
int main() {
    string a,b;
    int c = 0;
    cin>>a;
    cin>>b;
    srand(time(NULL));
    c = ((rand()%900+100)*100000000+rand()*10000+rand())%1000000000;
    cout<<"<?xml version=\"1.0\"?>\n<WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\">\n	<name>"<<a<<"</name>\n	<SSIDConfig>\n		<SSID>\n			<name>"<<a<<"</name>\n		</SSID>\n	</SSIDConfig>\n	<connectionType>ESS</connectionType>\n	<connectionMode>auto</connectionMode>\n	<MSM>\n		<security>\n			<authEncryption>\n				<authentication>WPA2PSK</authentication>\n				<encryption>AES</encryption>\n				<useOneX>false</useOneX>\n			</authEncryption>\n			<sharedKey>\n				<keyType>passPhrase</keyType>\n				<protected>false</protected>\n				<keyMaterial>"<<b<<"</keyMaterial>\n			</sharedKey>\n		</security>\n	</MSM>\n	<MacRandomization xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v3\">\n		<enableRandomization>false</enableRandomization>\n		<randomizationSeed>"<<c<<"</randomizationSeed>\n	</MacRandomization>\n</WLANProfile>";
}