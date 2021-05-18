FILESEXTRAPATHS_prepend := "${THISDIR}/${BPN}:"

SRC_URI += "file://rtcinit.sh \
            file://adbd.sh \
"

do_install_append () {
  install -m 0755 ${WORKDIR}/rtcinit.sh ${D}${sysconfdir}/init.d
  install -m 0755 ${WORKDIR}/adbd.sh ${D}${sysconfdir}/init.d
  update-rc.d -r ${D} rtcinit.sh start 50 2 3 4 5 .
  update-rc.d -r ${D} adbd.sh start 40 S . stop 01 6 .
}

