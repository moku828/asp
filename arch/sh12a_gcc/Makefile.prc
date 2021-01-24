#
#  $Id: Makefile.prc 2084 2011-05-12 08:03:41Z mit-kimai $
#

#
#		Makefile �Υ������ƥ������¸���ʥץ����å���¸���ˡ�SH12A�ѡ�
#


#
#  ����ѥ��륪�ץ����
#
COPTS := $(COPTS)
LDFLAGS := -nostdlib $(LDFLAGS)
CDEFS := $(CDEFS) -DTOPPERS_LABEL_ASM
LIBS := $(LIBS)  -L.. -lfreetype -lgcc -lc

#
#  �����ƥॵ���ӥ��˴ؤ������
#  ��kernel_cfg_asm.S�򥷥��ƥॵ���ӥ��˴ޤ��Τϡ�Ŭ�ڤǤϤʤ�����
#  ����������ѥ��롦���ץ������ä˥��󥯥롼�ɥѥ���
#  �����������ͥ롦�饤�֥��ι���
#  �����Թ�ǡ��ص��塢�����˴ޤ�Ƥ��롣
#
SYSSVC_ASMOBJS := $(SYSSVC_ASMOBJS) kernel_cfg_asm.o
REALCLEAN_FILES := $(REALCLEAN_FILES) kernel_cfg_asm.S

#
#  ����ե�����졼���ط����ѿ������
#
CFG_TABS := $(CFG_TABS) --cfg1-def-table $(PRCDIR)/prc_def.csv

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR := $(KERNEL_DIR) $(PRCDIR)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o
KERNEL_CFLAGS := $(KERNEL_CFLAGS) -fno-strict-aliasing

#
#  ��¸�ط������
#
cfg1_out.c: $(PRCDIR)/prc_def.csv
kernel_cfg.timestamp: $(PRCDIR)/prc.tf
$(OBJFILE): $(PRCDIR)/prc_check.tf

#
#  ���ե��åȥե����������Τ�������
#
OFFSET_TF = $(PRCDIR)/prc_offset.tf
