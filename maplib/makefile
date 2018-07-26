#
#  Configurar para compilação cruzada com yocto:
#
#  source /opt/yocto/poky/2.2/environment-setup-core2-32-poky-linux
#  ou
#  source /opt/yocto/poky/1.3.2/environment-setup-core2-poky-linux
#
#  TODO: fazer para o ARM DS
#

app: conv.c pcie_memmap.c pcie_memmap.h
	$(CC) -o conv_fpga conv.c pcie_memmap.c -Wall
	#cp conv_fpga /opt/tftp
	#cp rodar_fpga.sh /opt/tftp
	#cp entrada.dat /opt/tftp

clean:
	rm -rf *.o conv_fpga
