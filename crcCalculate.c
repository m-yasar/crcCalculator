#include <stdio.h>
#include <stdint.h>

uint8_t dizi[9]={0x02,0x10,0x07,0xD0,0x00,0x01,0x02,0x07,0x00};

uint16_t crc16(uint16_t crc, uint8_t *buf, int len)
{
    uint16_t POLY=0xa001;
    while (len--) {
        crc ^= *buf++;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
        crc = crc & 1 ? (crc >> 1) ^ POLY : crc >> 1;
    }
    crc = (((crc>>8)&0xff) | (crc<<8)); //Bytelerin swapli gitmesi isteniyorsa yazilmali aksi taktirde yorum satiri yapilabilir
    return crc;
}

int main(){
    uint16_t CalculatedCRC=crc16(0xFFFF,dizi,9);  
	printf("%X\n", CalculatedCRC);
    return 0;
}