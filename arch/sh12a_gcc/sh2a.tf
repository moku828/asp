$ 
$		������¸�ƥ�ץ졼�ȡ�SH2A�ѡ�
$ 

$ 
$  NMI�γ�����ֹ�
$ 
$TINTNO_NMI = 11$

$ 
$  �����°����Υ������åȰ�¸���Ѥ���ӥå�
$ 
$TARGET_INTATR = TA_POSEDGE | TA_NEGEDGE | TA_LOWLEVEL$

$ 
$  CFG_INT������Ǥ�������°���Υꥹ��
$ 	��������
$ 	������TA_ENAINT��̵ͭ�Ͼ�ά
$ 

$ 
$ IRQ����ߤǻ��ѤǤ�������°��
$ 		���ݥ��ƥ��֥��å�
$ 		���ͥ��ƥ��֥��å�
$ 		��ξ�ƥ��֥��å�
$ 		������٥�
$ 
$valid_irq_intatr_list = {
	0,
	TA_POSEDGE,
	TA_NEGEDGE,
	TA_BOTHEDGE,
	TA_EDGE,
	TA_EDGE | TA_POSEDGE,
	TA_EDGE | TA_NEGEDGE,
	TA_EDGE | TA_BOTHEDGE,
	TA_LOWLEVEL
}$

$ 
$ NMI�ǻ��ѤǤ�������°��
$ 		���ݥ��ƥ��֥��å�
$ 		���ͥ��ƥ��֥��å�
$ 
$valid_nmi_intatr_list = {
	TA_POSEDGE,
	TA_NEGEDGE,
	TA_EDGE,
	TA_EDGE | TA_POSEDGE,
	TA_EDGE | TA_NEGEDGE
}$

$ 
$  �ץ��å���¸�Υƥ�ץ졼�ȥե�����Υ��󥯥롼��
$ 
$INCLUDE "sh12a_gcc/prc.tf"$
