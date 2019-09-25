1. init git
./repo init -u git://codeaurora.org/quic/qsdk/releases/manifest/qstak -b release -m caf_AU_LINUX_QSDK_NHSS.QSDK.10.0_TARGET_ALL.10.0.3440.3836.xml --repo-url=git://codeaurora.org/tools/repo.git --repo-branch=caf-stable

2. Download fils
./repo sync --no-tags -c

3. Prepare dl directory
mkdir -p qsdk/dl

4. Prepare for files
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wifi/qsdk-ieee1905-security/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wifi/qsdk-qca-art/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wifi/qsdk-qca-wifi/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wifi/qsdk-qca-wlan/* qsdk
cp -rf ./chipcode/WLAN.HK.2.0/wlan_proc/src/components/qca-wifi-fw-src-component-cmn-WLAN.HK.2.0* qsdk/dl/
cp -rf ./chipcode/WLAN.HK.2.0/wlan_proc/pkg/wlan_proc/bin/QCA8074/qca-wifi-fw-QCA8074-WLAN.HK.2.0* qsdk/dl/
tar xf ./chipcode/WLAN.BL.3.10/cnss_proc/src/components/qca-wifi-fw-src-component-cmn-WLAN.BL.3.10-00057-S-1.tgz -C qsdk/dl
tar xf ./chipcode/WLAN.BL.3.10/cnss_proc/src/components/qca-wifi-fw-src-component-halphy_tools-WLAN.BL.3.10-00057-S-1.tgz -C qsdk/dl
cp -rf ./chipcode/WLAN.BL.3.10/cnss_proc/src/components/* qsdk/dl
cp -rf ./chipcode/WLAN.BL.3.10/cnss_proc/bin/QCA9888/hw.2/* qsdk/dl
cp -rf ./chipcode/WLAN.BL.3.10/cnss_proc/bin/AR900B/hw.2/* qsdk/dl
cp -rf ./chipcode/WLAN.BL.3.10/cnss_proc/bin/QCA9984/hw.1/* qsdk/dl
cp -rf ./chipcode/WLAN.BL.3.10/cnss_proc/bin/IPQ4019/hw.1/* qsdk/dl
cp -rf ./chipcode/CNSS.PS.3.10/qca-wifi-fw-AR988* qsdk/dl
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/meta-tools/ .
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/common-tools/* qsdk/
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qsdk-qca-nss/* qsdk/
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-lib/* qsdk/
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/BLUETOPIA/qca-bluetopia/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/RSRC-NSS-MDUMP/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-mcs-apps/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-nss-userspace/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-time-services/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-qmi-framework/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/gpio-debug/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-diag/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-cnss-daemon/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/athtestcmd/* qsdk
tar xjf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-IOT/qca-IOT.tar.bz2 -C qsdk
sed -i '/QCAHKSWPL_SILICONZ/c\PKG_VERSION:=WLAN.HK.2.0-01576-QCAHKSWPL_SILICONZ-1' qsdk/qca/feeds/qca_hk/net/qca-hk/Makefile
cp ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/QSDK-Base/qca-nss-fw-eip-hk/BIN-EIP197.HK.* qsdk/dl/

cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/RBIN-NSS-RETAIL/BIN-NSS.HK* qsdk/dl/

cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Hyfi/hyfi/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wifi/qsdk-whc/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wifi/qsdk-whcpy/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wigig/qsdk-qca-wigig/* qsdk
cp -rf ./chipcode/NHSS.QSDK.10.0/apss_proc/out/proprietary/Wigig/qsdk-wigig-utils/* qsdk
rm -rf qsdk/qca/feeds/wigig-utils/tools
rm -rf qsdk/qca/feeds/wigig-utils/libwigigaoa

5. Build the software
cd qsdk
./scripts/feeds update -a
./scripts/feeds install -a -f

5.1 Premium 32-bit
cp -rf qca/configs/qsdk/ipq_premium.config .config
sed -i "s/TARGET_ipq_ipq806x/TARGET_ipq_ipq807x/g" .config
make defconfig
sed -i -e "/CONFIG_PACKAGE_qca-wifi-fw-hw5-10.4-asic/d" .config
make V=s

5.2 Premium 64-bit
cp -rf qca/configs/qsdk/ipq_premium.config .config
sed -i "s/TARGET_ipq_ipq806x/TARGET_ipq_ipq807x_64/g" .config
make defconfig
sed -i -e "/CONFIG_PACKAGE_qca-wifi-fw-hw5-10.4-asic/d" .config
make V=s







