include $(TOPDIR)/rules.mk

PKG_NAME:=gluon-mesh-olsrd
PKG_VERSION=1

PKG_BUILD_DEPENDS += libjson-c

include ../gluon.mk

define Package/gluon-mesh-olsrd
	TITLE:=olsrd mesh
	DEPENDS:= \
		+gluon-core \
		+kmod-macvlan \
		+olsrd \
		+oonf-olsrd2 \
		+firewall4 \
		+libgluonutil \
		+libjson-c \
		+libubox +libuclient \
		+olsrd-mod-jsoninfo \
		+olsrd-mod-httpinfo \
		+olsrd-mod-txtinfo \
		+liblua \
		+ip-full \
		+gluon-mesh-layer3-common \
		+gluon-l3roamd \
		+lua-jsonc \
		+gluon-state-check
	PROVIDES:=gluon-mesh-provider
endef

define Package/gluon-mesh-olsrd/install
	$(Gluon/Build/Install)

	$(INSTALL_DIR) $(1)/usr/lib/lua/gluon
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/olsrd.so $(1)/usr/lib/lua/gluon/
	$(INSTALL_DIR) $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libolsrdhelper.so $(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/olsrd-debug $(1)/usr/bin/olsrd-debug
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/olsr-respondd $(1)/usr/bin/olsr-respondd

ifdef CONFIG_GLUON_BASE
	rm -rf $(1)/lib/gluon/upgrade/
endif
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib/lua/gluon
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/olsrd.so $(1)/usr/lib/lua/gluon/
	$(INSTALL_DIR) $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libolsrdhelper.so $(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/include/gluon-mesh-olsrd
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libolsrdhelper.h $(1)/usr/include/gluon-mesh-olsrd/
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libolsrdhelper.pc $(1)/usr/lib/pkgconfig/
endef


$(eval $(call BuildPackageGluon,gluon-mesh-olsrd))
