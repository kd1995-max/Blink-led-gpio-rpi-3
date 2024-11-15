include $(TOPDIR)/rules.mk                                                      

LUCI_TITLE:=LuCI Blink LED App for js-based LuCI                                
LUCI_DEPENDS:=+luci-base +blink-led                                             

include $(TOPDIR)/feeds/luci/luci.mk                                            

# call BuildPackage - OpenWrt buildroot signature                                
$(eval $(call BuildPackage,luci-app-blink))

