include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-wireless-encryption-wpa3-openssl

include ../gluon.mk

define Package/gluon-wireless-encryption-wpa3-openssl
  DEPENDS:=+hostapd-openssl
  TITLE:=Package for supporting WPA3 encrypted wireless networks
endef

define Package/gluon-wireless-encryption-wpa3-openssl/install
	$(INSTALL_DIR) $(1)/lib/gluon/features

	touch $(1)/lib/gluon/features/wpa2
	touch $(1)/lib/gluon/features/wpa3
endef

$(eval $(call BuildPackageGluon,gluon-wireless-encryption-wpa3-openssl))
