include $(TOPDIR)/rules.mk

PKG_NAME:=blink-led
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=LED Blinker for GPIO
	DEPENDS:=+libubox
endef

define Package/$(PKG_NAME)/description
	A simple program to blink an LED connected to GPIO on OpenWRT
endef

# Copy source and include files to the build directory
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) -r ./files/src $(PKG_BUILD_DIR)/
	$(CP) -r ./files/include $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include \
		-o $(PKG_BUILD_DIR)/blink_led \
		$(PKG_BUILD_DIR)/src/blink_led.c \
		$(PKG_BUILD_DIR)/src/gpio.c \
		$(PKG_BUILD_DIR)/src/led_control.c \
		$(PKG_BUILD_DIR)/src/uloop_setup.c \
		$(TARGET_LDFLAGS) -lubox
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/blink_led $(1)/usr/bin/blink_led
endef

$(eval $(call BuildPackage,$(PKG_NAME)))

