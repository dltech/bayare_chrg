#general paths
IC = STM8S003F3P6
TARGET = result/bayare_chrg
ODIR = bin
LIB_DIR = lib
REG_DIR = lib/regs

#sources
MAIN_SRC = main.c
SOURCES  = $(LIB_DIR)/gpio.c
SOURCES += $(REG_DIR)/timer.c
SOURCES += $(REG_DIR)/adc.c

INCLUDES   = -I $(LIB_DIR)/
INCLUDES  += -I $(REG_DIR)/
INCLUDES  += -I /

#main information
CC = sdcc
CFLAGS = -opt-code-size  -std-c89 -allow-unsafe-read -mstm8
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
	@$(CC) $(CFLAGS) $(MAIN_SRC) $(RELS) -o $@
