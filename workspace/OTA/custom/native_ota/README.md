native_ota:
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
partition scheme: facctory appl, ota_0 and ota_1

process flow: 
1)On first boot, the bootloader will load the image contained on the `factory` partition (i.e. the example image). This firmware triggers an OTA upgrade. 
2)It will download a new image from an HTTPS server and save it into the `OTA_0` partition. 
3)Next, it updates the `ota_data` partition to indicate which app should boot after the next reset. Upon reset, the bootloader  reads the contents of the `ota_data` partition to determine which application is selected to run.


