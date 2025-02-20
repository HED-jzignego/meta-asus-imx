SUMMARY = "Qualcomm WiFi driver for QCA module 9377 and 6174"
LICENSE = "BSD & GPLv2"
LIC_FILES_CHKSUM = "file://CORE/HDD/src/wlan_hdd_main.c;beginline=1;endline=20;md5=026b7328d0846296910939c71185e59c;"

QCACLD_SRC ?= "git://source.codeaurora.org/external/imx/qcacld-2.0-imx.git;protocol=https"
SRC_URI = "${QCACLD_SRC};branch=caf/CNSS.LEA.NRT_3.1"
SRCREV = "57806f25fc9590751b49ad0a509b113d19686b1b"

S = "${WORKDIR}/git"

inherit module

EXTRA_OEMAKE += " \
    CONFIG_CFG80211_INTERNAL_REGDB=y \
    CONFIG_HDD_WLAN_WAIT_TIME=10000 \
    CONFIG_LINUX_QCMBR=y \
    CONFIG_NON_QC_PLATFORM=y \
    CONFIG_PMF_SUPPORT=y \
    TARGET_BUILD_VARIANT=user \
"

RDEPENDS_${PN} = "qca-tools"
