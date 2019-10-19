TOP_DIR=$(pwd)
PACKAGE_DIR=${TOP_DIR}/package
TAR_NAME=demo.tar.gz
RPM_MACRO_FILE=/usr/lib/rpm/macros
RPM_INSTALL_DIR=/home/demo
#################################################
# mk demo
###############################################
mkdir -p install/bin
echo "hello_rpm_demo" > install/bin/rpm_demo.sh
tar czvf ${TAR_NAME} install

###############################################
# mk package
##############################################
#clean en
rm -rf ${PACKAGE_DIR}/*

#build_package_dir
mkdir -pv ${PACKAGE_DIR}/{BUILD,BUILDROOT,RPMS,SOURCES,SPECS,SRPMS}
mv ${TAR_NAME} ${PACKAGE_DIR}/SOURCES/
cp ${TOP_DIR}/demo.spec ${PACKAGE_DIR}/SPECS/

#set build_dir
echo "%_topdir /home/code/debug/test/package" > ~/.rpmmacros

#set en for no check for install
sed -i.bak 's/%__check_files/#%__check_files/g' ${RPM_MACRO_FILE}

#build source an bin
rpmbuild -ba  ${PACKAGE_DIR}/SPECS/demo.spec

#recover check for install
cp ${RPM_MACRO_FILE}.bak ${RPM_MACRO_FILE}
rm -rf ${RPM_MACRO_FILE}.bak

###########################
# watch package is ok
##########################
rpm -qlp ${PACKAGE_DIR}/RPMS/x86_64/*
rpm -ivh ${PACKAGE_DIR}/RPMS/x86_64/suite*
ls -l ${RPM_INSTALL_DIR}/*
