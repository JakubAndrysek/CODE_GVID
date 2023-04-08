#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Literatura
// https://www.samuraj-cz.com/clanek/tcpip-adresy-masky-subnety-a-vypocty/



// https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0')


typedef struct {
	int a;
	int b;
	int c;
	int d;
} IpAdresa;


void nastavIpAdresu(IpAdresa *ip, int a, int b, int c, int d) {
	ip->a = a;
	ip->b = b;
	ip->c = c;
	ip->d = d;
}

void tiskniIpAdresu(IpAdresa ip) {
	printf("IP addresa: %d.%d.%d.%d\n", ip.a, ip.b, ip.c, ip.d);
	printf("IP addresa: "BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"."BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(ip.a), BYTE_TO_BINARY(ip.b), BYTE_TO_BINARY(ip.c), BYTE_TO_BINARY(ip.d));
}

bool zkontrolujRozsah(int castIp) {
	if(castIp < 0 || castIp > 255) {
		return false;
	}
	return true;
}

bool zkontrolujIpAddresu(IpAdresa ip) {
	if(zkontrolujRozsah(ip.a) && zkontrolujRozsah(ip.b) && zkontrolujRozsah(ip.c) && zkontrolujRozsah(ip.d)) {
		return true;
	}
	return false;
}

void kontrolaIpAdresy(IpAdresa ip) {
	if(zkontrolujIpAddresu(ip)) {
		printf("IpAdresa je v poradku\n");
	} else {
		printf("IpAdresa nesplnuje rozsah\n");
	}
}

// Udelame binarni AND ip adresy a masky
// 11000000.01111100.00100100.00001010 (192.124.36.10) - IP addresa
// 11111111.11111111.11110000.00000000 (255.255.240.0) - maska
// 11000000.01111100.00100000.00000000 (192.124.32.0)  - adresa nadrazene site
IpAdresa ipNadrazenaSit(IpAdresa ip, IpAdresa maska) {
	IpAdresa nadrazena;
	uint8_t ip_a = ip.a & maska.a;
	uint8_t ip_b = ip.b & maska.b;
	uint8_t ip_c = ip.c & maska.c;
	uint8_t ip_d = ip.d & maska.d;
	nastavIpAdresu(&nadrazena, ip_a, ip_b, ip_c, ip_d);
	return nadrazena;
}


// Zneguji masku a udelam binarni AND
// 11000000.01111100.00100100.00001010 (192.124.36.10) - IP addresa
// 11111111.11111111.11110000.00000000 (255.255.240.0) - maska
// 00000000.00000000.00000100.00001010 (0.0.4.10)      - adresa podsite
IpAdresa ipPodsite(IpAdresa ip, IpAdresa maska) {
	IpAdresa podsit;
	uint8_t ip_a = ip.a & (~maska.a);
	uint8_t ip_b = ip.a & (~maska.b);
	uint8_t ip_c = ip.c & (~maska.c);
	uint8_t ip_d = ip.d & (~maska.d);
	nastavIpAdresu(&podsit, ip_a, ip_b, ip_c, ip_d);
	return podsit;
}


int main() {

	IpAdresa ip;
	nastavIpAdresu(&ip, 192, 124, 36, 10);

	tiskniIpAdresu(ip);
	kontrolaIpAdresy(ip);


	IpAdresa maska;
	nastavIpAdresu(&maska, 255, 255, 240, 0);

	IpAdresa adresaNadrazeneSite = ipNadrazenaSit(ip, maska);
	printf("Nadrazena sit: \n");
	tiskniIpAdresu(adresaNadrazeneSite);


	IpAdresa adresePodsite = ipPodsite(ip, maska);
	printf("Podsit: \n");
	tiskniIpAdresu(adresePodsite);

	return 0;
}