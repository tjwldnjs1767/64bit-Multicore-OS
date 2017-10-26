int main(int argc, char **argv) {
    int iTotalSelectorCount = 1024;
    int iSectorNum = 2;
    int iHeadNum = 0;
    int iTrackNum = 0;

    char *pcTargetAddress = (char *) 0x10000;

    while (1) {
        if (iTotalSelectorCount == 0)
            break;
        iTotalSelectorCount--;

        if (BIOSReadOneSector(iSectorNum, iHeadNum, iTrackNum, pcTargetAddress) == ERROR)
            HandleDiskError();

        pcTargetAddress = pcTargetAddress + 0x200;

        iSectorNum++;

        if (iSectorNum < 19)
            continue;

        iHeadNum = iHeadNum ^ 0x01;
        iSectorNum = 1;

        if(iHeadNum != 0)
            continue;

        iTrackNum++;
    }
    return 0;
}

int HandleDiskError() {
    printf("DISK Error");
    while (1);
}