$ 
$ 		�ѥ�3�Υץ��å���¸�ƥ�ץ졼�ȡ�SH12A�ѡ�
$ 

$ 
$  �����å��ΰ����Ƭ���Ϥ����ؿ�
$ �����������ƥ������¸���ǥ�����������֥�å��Υǡ�����¤��
$ �����ȼ���������Ƥ���Τǡ����¸�����餳�δؿ����ƤӽФ���롣
$ 
$ ����������������������֥�å���TINIB�ˤ���Ƭ����
$ 
$FUNCTION GET_STK_TSKINICTXB$
	$p_tinib = ARGV[1]$
	$stksz = PEEK(p_tinib + offsetof_TINIB_TSKINICTXB_stksz, sizeof_SIZE)$
	$stk_bottom = PEEK(p_tinib + offsetof_TINIB_TSKINICTXB_stk_bottom, sizeof_void_ptr)$
	$RESULT = stk_bottom - stksz$
$END$


$ 
$  ɸ��ƥ�ץ졼�ȥե�����Υ��󥯥롼��
$ 
$INCLUDE "kernel/kernel_check.tf"$
