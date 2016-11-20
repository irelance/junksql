
int crc16(char* str){
    int i = 0,j = 0,crc16 = 0xffff,len=strlen(str);
    for (i = 0;i < len;i++){
        crc16 = crc16 ^ (int)str[i];
        for (j = 0;j < 8;j++){
            if (crc16 & 0x01)
                crc16 = (crc16 >> 1) ^ 0xa001;
            else crc16 = crc16 >> 1;
        }
    }
    return crc16;
}

int str2int(char *str, int bit){
    int sum=0,i,len=strlen(str);
    for(i=0;i<len;i++){
        sum = sum << bit;
        sum+=(int)str[i];
    }
}

int divHash(char  *str, int hashLen){
    int sum = str2int(str, ACSII_UNSIGN);
    return sum%hashLen;
}

int mutiHash(char *str, float a, int hashLen){
    int sum = str2int(str, ACSII_UNSIGN);
    return (int)((sum*a-(int) sum*a)*hashLen);
}

int fibonacci16(char *str){
    int sum = str2int(str, ACSII_UNSIGN);
    return (sum * 40503)>>28;
}

int nohash(char* str){
  return 0;
}
