#                                                                                
# Copyright (C) 2008-2024                                                        
#                                                                                
# This is free software, licensed under the Apache License, Version 2.0 .        
#                                                                                

include $(TOPDIR)/rules.mk                                                      

LUCI_TITLE:=LuCI Blink LED App for js-based LuCI                                
LUCI_DEPENDS:=+luci-base +blink-led                                             

include $(TOPDIR)/feeds/luci/luci.mk                                            

# call BuildPackage - OpenWrt buildroot signature                                
$(eval $(call BuildPackage,luci-app-blink))

