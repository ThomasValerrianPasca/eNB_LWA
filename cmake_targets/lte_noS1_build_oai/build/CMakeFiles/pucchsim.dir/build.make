# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build

# Include any dependencies generated for this target.
include CMakeFiles/pucchsim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pucchsim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pucchsim.dir/flags.make

CMakeFiles/messages_xml.h: CMakeFiles/messages.xml
CMakeFiles/messages_xml.h: CMakeFiles/Rel14/asn1_constants.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating CMakeFiles/messages_xml.h"
	sed -e 's/ *//' -e 's/"/\\"/g' -e 's/^/"/' -e 's/$$/\\n"/' /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/messages.xml > /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/messages_xml.h

CMakeFiles/messages.xml: CMakeFiles/R10.5/s1ap_decoder.c
CMakeFiles/messages.xml: CMakeFiles/R10.5/s1ap_encoder.c
CMakeFiles/messages.xml: CMakeFiles/R10.5/s1ap_xer_print.c
CMakeFiles/messages.xml: CMakeFiles/R10.5/s1ap_compare.c
CMakeFiles/messages.xml: CMakeFiles/R10.5/s1ap_ies_defs.h
CMakeFiles/messages.xml: CMakeFiles/Rel14/asn1_constants.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating CMakeFiles/messages.xml"
	gccxml -DCMAKE_BUILD_TYPE="RelWithDebInfo" -DCMAKER -DFIRMWARE_VERSION="No\ svn\ information" -DPACKAGE_VERSION="Branch:\ HEAD\ Abrev.\ Hash:\ \ Date:\ " -DPACKAGE_BUGREPORT="openair4g-devel@lists.eurecom.fr" -DXFORMS -DENABLE_ITTI -DRel14=1 -DS1AP_VERSION=R10 -DX2AP_VERSION=R11 -DNB_ANTENNAS_RX=2 -DNB_ANTENNAS_TX=4 -DNB_ANTENNAS_TXRX=2 -DOAI_USRP=1 -DNone=1 -DENABLE_SECURITY -DNO_RRM -DUSER_MODE -DOAI_NW_DRIVER_USE_NETLINK -DPACKAGE_NAME="lte-softmodem-nos1" -DENB_MODE -DENABLE_USE_CPU_EXECUTION_TIME -DENABLE_VCD -DLINUX -DLOG_NO_THREAD -DOPENAIR_LTE -DDRIVER2013 -DENABLE_FXP -DEXMIMO_IOT -DMAX_NUM_CCs=1 -DNEW_FFT -DOPENAIR1 -DPC_DSP -DPC_TARGET -DPHYSIM -DPHY_CONTEXT -DPUCCH -DENABLE_NAS_UE_LOGGING -DNAS_BUILT_IN_UE -DMAC_CONTEXT -DJUMBO_FRAME -DOPENAIR2 -DTRACE_RLC_MUTEX -DPDCP_USE_NETLINK -DLINK_ENB_PDCP_TO_IP_DRIVER -DNETTLE_VERSION_MAJOR=2 -DNETTLE_VERSION_MINOR=7 -DASN1_MINIMUM_VERSION=924 -I/home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/Rel14 -I/home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/R10.5 -I/home/oai/Downloads/LWA/openair3/S1AP -I/home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/R11.2 -I/home/oai/Downloads/LWA/openair2/X2AP -I/home/oai/Downloads/LWA/targets/ARCH/EXMIMO/USERSPACE/LIB -I/home/oai/Downloads/LWA/targets/ARCH/EXMIMO/DEFS -I/home/oai/Downloads/LWA/targets/ARCH/USRP/USERSPACE/LIB -I/home/oai/Downloads/LWA/targets/ARCH/BLADERF/USERSPACE/LIB -I/home/oai/Downloads/LWA/targets/ARCH/LMSSDR/USERSPACE/LIB -I/home/oai/Downloads/LWA/targets/ARCH/ETHERNET/USERSPACE/LIB -I/home/oai/Downloads/LWA/targets/ARCH/COMMON -I/home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles -I/home/oai/Downloads/LWA/openair2/COMMON -I/home/oai/Downloads/LWA/openair2/UTIL -I/home/oai/Downloads/LWA/openair2/UTIL/LOG -I/home/oai/Downloads/LWA/openair3/COMMON -I/home/oai/Downloads/LWA/openair3/UTILS -I/home/oai/Downloads/LWA/openair1 -I/home/oai/Downloads/LWA/openair2/NAS -I/home/oai/Downloads/LWA/openair2 -I/home/oai/Downloads/LWA/openair2/LAYER2/RLC -I/home/oai/Downloads/LWA/openair2/LAYER2/RLC/AM_v9.3.0 -I/home/oai/Downloads/LWA/openair2/LAYER2/RLC/UM_v9.3.0 -I/home/oai/Downloads/LWA/openair2/LAYER2/RLC/TM_v9.3.0 -I/home/oai/Downloads/LWA/openair2/LAYER2/PDCP_v10.1.0 -I/home/oai/Downloads/LWA/openair2/RRC/LITE/MESSAGES -I/home/oai/Downloads/LWA/openair2/RRC/LITE -I/home/oai/Downloads/LWA/openair3/RAL-LTE/INTERFACE-802.21/INCLUDE -I/home/oai/Downloads/LWA/openair3/RAL-LTE/LTE_RAL_ENB/INCLUDE -I/home/oai/Downloads/LWA/openair3/RAL-LTE/LTE_RAL_UE/INCLUDE -I/home/oai/Downloads/LWA/common/utils -I/home/oai/Downloads/LWA/common/utils/itti -I/home/oai/Downloads/LWA/openair3/NAS/COMMON -I/home/oai/Downloads/LWA/openair3/NAS/COMMON/API/NETWORK -I/home/oai/Downloads/LWA/openair3/NAS/COMMON/EMM/MSG -I/home/oai/Downloads/LWA/openair3/NAS/COMMON/ESM/MSG -I/home/oai/Downloads/LWA/openair3/NAS/COMMON/IES -I/home/oai/Downloads/LWA/openair3/NAS/COMMON/UTIL -I/home/oai/Downloads/LWA/openair3/SECU -I/home/oai/Downloads/LWA/openair3/SCTP -I/home/oai/Downloads/LWA/openair3/S1AP -I/home/oai/Downloads/LWA/openair2/X2AP -I/home/oai/Downloads/LWA/openair3/UDP -I/home/oai/Downloads/LWA/openair3/GTPV1-U -I/home/oai/Downloads/LWA/targets/COMMON -I/home/oai/Downloads/LWA/targets/ARCH/COMMON -I/home/oai/Downloads/LWA/targets/ARCH/EXMIMO/USERSPACE/LIB -I/home/oai/Downloads/LWA/targets/ARCH/EXMIMO/DEFS -I/home/oai/Downloads/LWA/openair2/ENB_APP -I/home/oai/Downloads/LWA/openair2/ENB_APP/CONTROL_MODULES/MAC -I/home/oai/Downloads/LWA/openair2/UTIL/OSA -I/home/oai/Downloads/LWA/openair2/UTIL/LFDS/liblfds6.1.1/liblfds611/inc -I/home/oai/Downloads/LWA/openair2/UTIL/LFDS/liblfds7.0.0/liblfds700/inc -I/home/oai/Downloads/LWA/openair2/UTIL/MEM -I/home/oai/Downloads/LWA/openair2/UTIL/LISTS -I/home/oai/Downloads/LWA/openair2/UTIL/FIFO -I/home/oai/Downloads/LWA/openair2/UTIL/OCG -I/home/oai/Downloads/LWA/openair2/UTIL/MATH -I/home/oai/Downloads/LWA/openair2/UTIL/TIMER -I/home/oai/Downloads/LWA/openair2/UTIL/OMG -I/home/oai/Downloads/LWA/openair2/UTIL/OTG -I/home/oai/Downloads/LWA/openair2/UTIL/CLI -I/home/oai/Downloads/LWA/openair2/UTIL/OPT -I/home/oai/Downloads/LWA/openair2/UTIL/OMV -I/home/oai/Downloads/LWA/openair2/RRC/LITE/MESSAGES -I/home/oai/Downloads/LWA/openair3/GTPV1-U/nw-gtpv1u/shared -I/home/oai/Downloads/LWA/openair3/GTPV1-U/nw-gtpv1u/include -I/home/oai/Downloads/LWA -I/home/oai/Downloads/LWA/common/utils/hashtable -I/home/oai/Downloads/LWA/common/utils/msc -I/home/oai/Downloads/LWA/openair2/UTIL/LFDS/liblfds6.1.1/liblfds611/src -I/home/oai/Downloads/LWA/openair2/UTIL/LFDS/liblfds7.0.0/liblfds700/src -I/usr/include/libxml2 -I/usr/include/libxml2 -I/usr/include/pgm-5.1 -I/usr/lib/x86_64-linux-gnu/pgm-5.1/include -I/usr/include/atlas -I/usr/include/X11 -I/home/oai/Downloads/LWA/common/utils/T -std=gnu89 -fxml=/home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/messages.xml /home/oai/Downloads/LWA/common/utils/itti/intertask_interface_types.h

CMakeFiles/Rel14/asn1_constants.h: /home/oai/Downloads/LWA/openair2/RRC/LITE/MESSAGES/asn1c/ASN1_files/RRC-e10.asn
	$(CMAKE_COMMAND) -E cmake_progress_report /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating CMakeFiles/Rel14/asn1_constants.h"
	/home/oai/Downloads/LWA/cmake_targets/tools/generate_asn1 /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/Rel14 /home/oai/Downloads/LWA/openair2/RRC/LITE/MESSAGES/asn1c/ASN1_files/RRC-e10.asn
	/home/oai/Downloads/LWA/cmake_targets/tools/fix_asn1 /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/Rel14 RRC Rel14

CMakeFiles/R10.5/s1ap_decoder.c: /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-CommonDataTypes.asn
CMakeFiles/R10.5/s1ap_decoder.c: /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-Constants.asn
CMakeFiles/R10.5/s1ap_decoder.c: /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-IEs.asn
CMakeFiles/R10.5/s1ap_decoder.c: /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-PDU.asn
	$(CMAKE_COMMAND) -E cmake_progress_report /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating CMakeFiles/R10.5/s1ap_decoder.c, CMakeFiles/R10.5/s1ap_encoder.c, CMakeFiles/R10.5/s1ap_xer_print.c, CMakeFiles/R10.5/s1ap_compare.c, CMakeFiles/R10.5/s1ap_ies_defs.h"
	/home/oai/Downloads/LWA/cmake_targets/tools/generate_asn1 /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/R10.5 /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-CommonDataTypes.asn /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-Constants.asn /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-IEs.asn /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-PDU.asn
	python /home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/asn1tostruct.py -f/home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-PDU-Contents.asn -o/home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/R10.5
	/home/oai/Downloads/LWA/cmake_targets/tools/fix_asn1 /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/R10.5 S1AP R10

CMakeFiles/R10.5/s1ap_encoder.c: CMakeFiles/R10.5/s1ap_decoder.c

CMakeFiles/R10.5/s1ap_xer_print.c: CMakeFiles/R10.5/s1ap_decoder.c

CMakeFiles/R10.5/s1ap_compare.c: CMakeFiles/R10.5/s1ap_decoder.c

CMakeFiles/R10.5/s1ap_ies_defs.h: CMakeFiles/R10.5/s1ap_decoder.c

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o: CMakeFiles/pucchsim.dir/flags.make
CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o: /home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o   -c /home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c > CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.i

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c -o CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.s

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.requires:
.PHONY : CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.requires

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.provides: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.requires
	$(MAKE) -f CMakeFiles/pucchsim.dir/build.make CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.provides.build
.PHONY : CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.provides

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.provides.build: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o: CMakeFiles/pucchsim.dir/flags.make
CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o: /home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o   -c /home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c > CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.i

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c -o CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.s

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.requires:
.PHONY : CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.requires

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.provides: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.requires
	$(MAKE) -f CMakeFiles/pucchsim.dir/build.make CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.provides.build
.PHONY : CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.provides

CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.provides.build: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o

# Object files for target pucchsim
pucchsim_OBJECTS = \
"CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o" \
"CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o"

# External object files for target pucchsim
pucchsim_EXTERNAL_OBJECTS =

pucchsim: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o
pucchsim: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o
pucchsim: CMakeFiles/pucchsim.dir/build.make
pucchsim: libSIMU.a
pucchsim: libUTIL.a
pucchsim: libSCHED_LIB.a
pucchsim: libPHY.a
pucchsim: libLFDS.a
pucchsim: libITTI.a
pucchsim: libLFDS7.a
pucchsim: CMakeFiles/pucchsim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable pucchsim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pucchsim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pucchsim.dir/build: pucchsim
.PHONY : CMakeFiles/pucchsim.dir/build

CMakeFiles/pucchsim.dir/requires: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/SIMULATION/LTE_PHY/pucchsim.c.o.requires
CMakeFiles/pucchsim.dir/requires: CMakeFiles/pucchsim.dir/home/oai/Downloads/LWA/openair1/PHY/TOOLS/lte_phy_scope.c.o.requires
.PHONY : CMakeFiles/pucchsim.dir/requires

CMakeFiles/pucchsim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pucchsim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pucchsim.dir/clean

CMakeFiles/pucchsim.dir/depend: CMakeFiles/messages_xml.h
CMakeFiles/pucchsim.dir/depend: CMakeFiles/messages.xml
CMakeFiles/pucchsim.dir/depend: CMakeFiles/Rel14/asn1_constants.h
CMakeFiles/pucchsim.dir/depend: CMakeFiles/R10.5/s1ap_decoder.c
CMakeFiles/pucchsim.dir/depend: CMakeFiles/R10.5/s1ap_encoder.c
CMakeFiles/pucchsim.dir/depend: CMakeFiles/R10.5/s1ap_xer_print.c
CMakeFiles/pucchsim.dir/depend: CMakeFiles/R10.5/s1ap_compare.c
CMakeFiles/pucchsim.dir/depend: CMakeFiles/R10.5/s1ap_ies_defs.h
	cd /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build /home/oai/Downloads/LWA/cmake_targets/lte_noS1_build_oai/build/CMakeFiles/pucchsim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pucchsim.dir/depend

