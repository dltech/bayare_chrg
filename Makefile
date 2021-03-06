#general paths
IC = STM8S003F3P6
TARGET = result/bayare_chrg
ODIR = bin
LIB_DIR = lib
REG_DIR = lib/regs

#sources
MAIN_SRC = main.c
SOURCES  = $(LIB_DIR)/gpio.c
SOURCES  += $(LIB_DIR)/pwm.c
SOURCES  += $(LIB_DIR)/system.c
SOURCES  += $(LIB_DIR)/analogue.c
SOURCES  += $(LIB_DIR)/button.c
SOURCES  += $(LIB_DIR)/tm1637.c
SOURCES  += $(LIB_DIR)/display.c
SOURCES  += $(LIB_DIR)/autocharge.c
SOURCES  += $(LIB_DIR)/charger.c

INCLUDES   = -I $(LIB_DIR)/
INCLUDES  += -I $(REG_DIR)/

#main information
CC = sdcc
CFLAGS = --std-c99 -mstm8 --opt-code-size --allow-unsafe-read
RELS = $(SOURCES:%.c=$(ODIR)/%.rel)

#main rule
all: $(TARGET).ihx
#rels
$(ODIR)/%.rel: %.c
	@echo "[compiling] $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
#link
$(TARGET).ihx: $(RELS)
	@echo "[linking] $@"
	@$(CC) $(CFLAGS) $(MAIN_SRC) $(RELS) $(INCLUDES) -o $@
# Clean rule
#.PHONY:
clean:
	@rm -rf $(ODIR)
	@rm -r $(TARGET).*
