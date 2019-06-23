#define _start		__kernel_start		
/***************************************************************
 *																
 *  ターゲット依存かつアプリケーション依存の処理（SH12A）		
 *																
 *	このファイルはコンフィギュレータにより自動生成されている。	
 *	修正する場合はテンプレートファイルを修正すること。			
 **************************************************************/
/*															
 *  割込みハンドラの入口処理								
 *															
 *　　レジスタ割当											
 *　　　　r7：割込み受付直後／CPU例外発生時のSRのコピー		
 *　　　　r6：割込みハンドラ／CPU例外ハンドラの先頭アドレス	
 *　　　　r5：割込み／CPU例外ハンドラ番号					
 *　　　　r4：_kernel_interrupt_entry／_kernel_exception_entry	
 *			（prc_support.S内での分岐先）					
 *															
 *	割込みとCPU例外の相違点									
 *	　　・CPU例外ハンドラに引数を与える						
 *	　　・CPU例外では、例外発生時のIPMと同じ値で割込みを許可する	
 *		（CPU例外により、IPMを変化させない）				
 *															
 *	　　・割込みハンドラの場合								
 *	　　  	割込み受付時にハードウェアがIPMを設定する		
 *	　　  	割込み許可にはこのIPMの値を用いる				
 *	　　・CPU例外ハンドラの場合								
 *	　　  	CPU例外受付時にIPMの値は変化しない				
 *	　　  	割込み許可にはCPU例外発生時のIPMの値を用いる	
 */															
	.section .vector_entry,"xa"  							

	.align 2                       							
__kernel_default_int_handler_entry_11:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_11,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_11,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_11:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_11:                     /* 割込み番号 */ 		
	.long  11 											

	.align 2                       							
__kernel_default_int_handler_entry_64:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_64,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_64,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_64:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_64:                     /* 割込み番号 */ 		
	.long  64 											

	.align 2                       							
__kernel_default_int_handler_entry_65:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_65,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_65,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_65:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_65:                     /* 割込み番号 */ 		
	.long  65 											

	.align 2                       							
__kernel_default_int_handler_entry_66:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_66,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_66,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_66:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_66:                     /* 割込み番号 */ 		
	.long  66 											

	.align 2                       							
__kernel_default_int_handler_entry_67:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_67,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_67,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_67:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_67:                     /* 割込み番号 */ 		
	.long  67 											

	.align 2                       							
__kernel_default_int_handler_entry_68:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_68,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_68,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_68:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_68:                     /* 割込み番号 */ 		
	.long  68 											

	.align 2                       							
__kernel_default_int_handler_entry_69:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_69,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_69,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_69:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_69:                     /* 割込み番号 */ 		
	.long  69 											

	.align 2                       							
__kernel_default_int_handler_entry_70:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_70,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_70,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_70:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_70:                     /* 割込み番号 */ 		
	.long  70 											

	.align 2                       							
__kernel_default_int_handler_entry_71:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_71,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_71,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_71:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_71:                     /* 割込み番号 */ 		
	.long  71 											

	.align 2                       							
__kernel_default_int_handler_entry_80:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_80,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_80,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_80:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_80:                     /* 割込み番号 */ 		
	.long  80 											

	.align 2                       							
__kernel_default_int_handler_entry_81:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_81,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_81,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_81:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_81:                     /* 割込み番号 */ 		
	.long  81 											

	.align 2                       							
__kernel_default_int_handler_entry_82:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_82,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_82,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_82:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_82:                     /* 割込み番号 */ 		
	.long  82 											

	.align 2                       							
__kernel_default_int_handler_entry_83:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_83,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_83,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_83:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_83:                     /* 割込み番号 */ 		
	.long  83 											

	.align 2                       							
__kernel_default_int_handler_entry_84:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_84,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_84,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_84:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_84:                     /* 割込み番号 */ 		
	.long  84 											

	.align 2                       							
__kernel_default_int_handler_entry_85:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_85,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_85,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_85:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_85:                     /* 割込み番号 */ 		
	.long  85 											

	.align 2                       							
__kernel_default_int_handler_entry_86:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_86,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_86,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_86:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_86:                     /* 割込み番号 */ 		
	.long  86 											

	.align 2                       							
__kernel_default_int_handler_entry_87:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_87,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_87,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_87:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_87:                     /* 割込み番号 */ 		
	.long  87 											

	.align 2                       							
__kernel_default_int_handler_entry_108:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_108,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_108,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_108:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_108:                     /* 割込み番号 */ 		
	.long  108 											

	.align 2                       							
__kernel_default_int_handler_entry_109:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_109,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_109,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_109:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_109:                     /* 割込み番号 */ 		
	.long  109 											

	.align 2                       							
__kernel_default_int_handler_entry_112:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_112,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_112,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_112:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_112:                     /* 割込み番号 */ 		
	.long  112 											

	.align 2                       							
__kernel_default_int_handler_entry_113:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_113,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_113,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_113:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_113:                     /* 割込み番号 */ 		
	.long  113 											

	.align 2                       							
__kernel_default_int_handler_entry_116:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_116,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_116,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_116:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_116:                     /* 割込み番号 */ 		
	.long  116 											

	.align 2                       							
__kernel_default_int_handler_entry_117:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_117,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_117,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_117:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_117:                     /* 割込み番号 */ 		
	.long  117 											

	.align 2                       							
__kernel_default_int_handler_entry_120:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_120,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_120,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_120:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_120:                     /* 割込み番号 */ 		
	.long  120 											

	.align 2                       							
__kernel_default_int_handler_entry_121:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_121,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_121,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_121:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_121:                     /* 割込み番号 */ 		
	.long  121 											

	.align 2                       							
__kernel_default_int_handler_entry_124:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_124,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_124,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_124:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_124:                     /* 割込み番号 */ 		
	.long  124 											

	.align 2                       							
__kernel_default_int_handler_entry_125:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_125,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_125,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_125:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_125:                     /* 割込み番号 */ 		
	.long  125 											

	.align 2                       							
__kernel_default_int_handler_entry_128:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_128,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_128,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_128:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_128:                     /* 割込み番号 */ 		
	.long  128 											

	.align 2                       							
__kernel_default_int_handler_entry_129:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_129,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_129,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_129:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_129:                     /* 割込み番号 */ 		
	.long  129 											

	.align 2                       							
__kernel_default_int_handler_entry_132:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_132,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_132,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_132:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_132:                     /* 割込み番号 */ 		
	.long  132 											

	.align 2                       							
__kernel_default_int_handler_entry_133:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_133,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_133,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_133:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_133:                     /* 割込み番号 */ 		
	.long  133 											

	.align 2                       							
__kernel_default_int_handler_entry_136:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_136,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_136,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_136:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_136:                     /* 割込み番号 */ 		
	.long  136 											

	.align 2                       							
__kernel_default_int_handler_entry_137:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_137,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_137,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_137:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_137:                     /* 割込み番号 */ 		
	.long  137 											

	.align 2                       							
__kernel_default_int_handler_entry_140:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_140,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_140,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_140:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_140:                     /* 割込み番号 */ 		
	.long  140 											

	.align 2                       							
__kernel_default_int_handler_entry_141:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_141,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_141,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_141:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_141:                     /* 割込み番号 */ 		
	.long  141 											

	.align 2                       							
__kernel_default_int_handler_entry_144:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_144,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_144,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_144:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_144:                     /* 割込み番号 */ 		
	.long  144 											

	.align 2                       							
__kernel_default_int_handler_entry_145:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_145,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_145,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_145:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_145:                     /* 割込み番号 */ 		
	.long  145 											

	.align 2                       							
__kernel_default_int_handler_entry_148:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_148,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_148,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_148:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_148:                     /* 割込み番号 */ 		
	.long  148 											

	.align 2                       							
__kernel_default_int_handler_entry_149:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_149,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_149,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_149:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_149:                     /* 割込み番号 */ 		
	.long  149 											

	.align 2                       							
__kernel_default_int_handler_entry_152:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_152,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_152,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_152:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_152:                     /* 割込み番号 */ 		
	.long  152 											

	.align 2                       							
__kernel_default_int_handler_entry_153:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_153,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_153,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_153:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_153:                     /* 割込み番号 */ 		
	.long  153 											

	.align 2                       							
__kernel_default_int_handler_entry_156:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_156,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_156,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_156:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_156:                     /* 割込み番号 */ 		
	.long  156 											

	.align 2                       							
__kernel_default_int_handler_entry_157:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_157,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_157,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_157:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_157:                     /* 割込み番号 */ 		
	.long  157 											

	.align 2                       							
__kernel_default_int_handler_entry_160:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_160,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_160,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_160:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_160:                     /* 割込み番号 */ 		
	.long  160 											

	.align 2                       							
__kernel_default_int_handler_entry_161:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_161,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_161,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_161:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_161:                     /* 割込み番号 */ 		
	.long  161 											

	.align 2                       							
__kernel_default_int_handler_entry_164:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_164,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_164,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_164:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_164:                     /* 割込み番号 */ 		
	.long  164 											

	.align 2                       							
__kernel_default_int_handler_entry_165:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_165,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_165,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_165:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_165:                     /* 割込み番号 */ 		
	.long  165 											

	.align 2                       							
__kernel_default_int_handler_entry_168:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_168,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_168,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_168:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_168:                     /* 割込み番号 */ 		
	.long  168 											

	.align 2                       							
__kernel_default_int_handler_entry_169:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_169,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_169,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_169:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_169:                     /* 割込み番号 */ 		
	.long  169 											

	.align 2                       							
__kernel_default_int_handler_entry_170:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_170,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_170,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_170:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_170:                     /* 割込み番号 */ 		
	.long  170 											

	.align 2                       							
__kernel_default_int_handler_entry_171:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_171,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_171,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_171:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_171:                     /* 割込み番号 */ 		
	.long  171 											

	.align 2                       							
__kernel_default_int_handler_entry_172:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_172,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_172,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_172:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_172:                     /* 割込み番号 */ 		
	.long  172 											

	.align 2                       							
__kernel_default_int_handler_entry_173:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_173,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_173,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_173:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_173:                     /* 割込み番号 */ 		
	.long  173 											

	.align 2                       							
__kernel_default_int_handler_entry_174:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_174,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_174,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_174:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_174:                     /* 割込み番号 */ 		
	.long  174 											

	.global __kernel_target_timer_handler_INHNO_TIMER											
	.align 2                       							
__kernel_target_timer_handler_INHNO_TIMER:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
	mov.l r5,@-r15											
	mov.l r4,@-r15											
#endif /* USE_BANKED_REG */   								
	stc   sr,r7								/* SRの保存 */ 	
	mov.l _iipm_disall___kernel_target_timer_handler_INHNO_TIMER,r6							
	ldc	  r6,sr								/* 全割込み禁止 */ 
		 /* 共有割込み入口処理 */    	
	mov.l _common_routine___kernel_target_timer_handler_INHNO_TIMER,r4 						
		 /* 割込みハンドラの先頭アドレス */ 
	mov.l _c_routine___kernel_target_timer_handler_INHNO_TIMER,r6     						
	mov.l _inhno___kernel_target_timer_handler_INHNO_TIMER,r5					/* 割込み番号 */ 
	jmp	  @r4												
	 nop													
	.align 2												
		 /* 割込み禁止用マスク */ 			
_iipm_disall___kernel_target_timer_handler_INHNO_TIMER:										
		 /* ipm以外のビットはゼロで良い */ 	
	.long  __kernel_iipm_disall								
_c_routine___kernel_target_timer_handler_INHNO_TIMER:/* 割込みハンドラの先頭アドレス */				
	.long  _target_timer_handler         					
		 /* cpu_support.S内の分岐先アドレス */			
_common_routine___kernel_target_timer_handler_INHNO_TIMER: 									
	.long  __kernel_interrupt_entry							
_inhno___kernel_target_timer_handler_INHNO_TIMER:							/* 割込み番号	*/	
	.long  175 											


	.align 2                       							
__kernel_default_int_handler_entry_176:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_176,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_176,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_176:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_176:                     /* 割込み番号 */ 		
	.long  176 											

	.align 2                       							
__kernel_default_int_handler_entry_177:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_177,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_177,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_177:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_177:                     /* 割込み番号 */ 		
	.long  177 											

	.align 2                       							
__kernel_default_int_handler_entry_178:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_178,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_178,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_178:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_178:                     /* 割込み番号 */ 		
	.long  178 											

	.align 2                       							
__kernel_default_int_handler_entry_179:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_179,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_179,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_179:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_179:                     /* 割込み番号 */ 		
	.long  179 											

	.align 2                       							
__kernel_default_int_handler_entry_180:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_180,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_180,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_180:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_180:                     /* 割込み番号 */ 		
	.long  180 											

	.align 2                       							
__kernel_default_int_handler_entry_181:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_181,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_181,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_181:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_181:                     /* 割込み番号 */ 		
	.long  181 											

	.align 2                       							
__kernel_default_int_handler_entry_182:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_182,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_182,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_182:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_182:                     /* 割込み番号 */ 		
	.long  182 											

	.align 2                       							
__kernel_default_int_handler_entry_183:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_183,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_183,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_183:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_183:                     /* 割込み番号 */ 		
	.long  183 											

	.align 2                       							
__kernel_default_int_handler_entry_184:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_184,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_184,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_184:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_184:                     /* 割込み番号 */ 		
	.long  184 											

	.align 2                       							
__kernel_default_int_handler_entry_185:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_185,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_185,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_185:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_185:                     /* 割込み番号 */ 		
	.long  185 											

	.align 2                       							
__kernel_default_int_handler_entry_186:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_186,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_186,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_186:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_186:                     /* 割込み番号 */ 		
	.long  186 											

	.align 2                       							
__kernel_default_int_handler_entry_187:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_187,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_187,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_187:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_187:                     /* 割込み番号 */ 		
	.long  187 											

	.align 2                       							
__kernel_default_int_handler_entry_188:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_188,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_188,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_188:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_188:                     /* 割込み番号 */ 		
	.long  188 											

	.align 2                       							
__kernel_default_int_handler_entry_189:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_189,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_189,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_189:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_189:                     /* 割込み番号 */ 		
	.long  189 											

	.align 2                       							
__kernel_default_int_handler_entry_190:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_190,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_190,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_190:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_190:                     /* 割込み番号 */ 		
	.long  190 											

	.align 2                       							
__kernel_default_int_handler_entry_191:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_191,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_191,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_191:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_191:                     /* 割込み番号 */ 		
	.long  191 											

	.align 2                       							
__kernel_default_int_handler_entry_192:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_192,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_192,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_192:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_192:                     /* 割込み番号 */ 		
	.long  192 											

	.align 2                       							
__kernel_default_int_handler_entry_193:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_193,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_193,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_193:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_193:                     /* 割込み番号 */ 		
	.long  193 											

	.align 2                       							
__kernel_default_int_handler_entry_194:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_194,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_194,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_194:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_194:                     /* 割込み番号 */ 		
	.long  194 											

	.align 2                       							
__kernel_default_int_handler_entry_195:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_195,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_195,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_195:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_195:                     /* 割込み番号 */ 		
	.long  195 											

	.align 2                       							
__kernel_default_int_handler_entry_196:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_196,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_196,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_196:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_196:                     /* 割込み番号 */ 		
	.long  196 											

	.align 2                       							
__kernel_default_int_handler_entry_197:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_197,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_197,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_197:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_197:                     /* 割込み番号 */ 		
	.long  197 											

	.align 2                       							
__kernel_default_int_handler_entry_198:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_198,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_198,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_198:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_198:                     /* 割込み番号 */ 		
	.long  198 											

	.align 2                       							
__kernel_default_int_handler_entry_199:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_199,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_199,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_199:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_199:                     /* 割込み番号 */ 		
	.long  199 											

	.align 2                       							
__kernel_default_int_handler_entry_200:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_200,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_200,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_200:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_200:                     /* 割込み番号 */ 		
	.long  200 											

	.align 2                       							
__kernel_default_int_handler_entry_201:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_201,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_201,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_201:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_201:                     /* 割込み番号 */ 		
	.long  201 											

	.align 2                       							
__kernel_default_int_handler_entry_202:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_202,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_202,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_202:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_202:                     /* 割込み番号 */ 		
	.long  202 											

	.align 2                       							
__kernel_default_int_handler_entry_203:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_203,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_203,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_203:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_203:                     /* 割込み番号 */ 		
	.long  203 											

	.align 2                       							
__kernel_default_int_handler_entry_204:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_204,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_204,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_204:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_204:                     /* 割込み番号 */ 		
	.long  204 											

	.align 2                       							
__kernel_default_int_handler_entry_205:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_205,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_205,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_205:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_205:                     /* 割込み番号 */ 		
	.long  205 											

	.align 2                       							
__kernel_default_int_handler_entry_206:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_206,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_206,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_206:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_206:                     /* 割込み番号 */ 		
	.long  206 											

	.align 2                       							
__kernel_default_int_handler_entry_207:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_207,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_207,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_207:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_207:                     /* 割込み番号 */ 		
	.long  207 											

	.align 2                       							
__kernel_default_int_handler_entry_208:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_208,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_208,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_208:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_208:                     /* 割込み番号 */ 		
	.long  208 											

	.align 2                       							
__kernel_default_int_handler_entry_209:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_209,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_209,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_209:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_209:                     /* 割込み番号 */ 		
	.long  209 											

	.align 2                       							
__kernel_default_int_handler_entry_210:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_210,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_210,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_210:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_210:                     /* 割込み番号 */ 		
	.long  210 											

	.align 2                       							
__kernel_default_int_handler_entry_211:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_211,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_211,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_211:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_211:                     /* 割込み番号 */ 		
	.long  211 											

	.align 2                       							
__kernel_default_int_handler_entry_212:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_212,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_212,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_212:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_212:                     /* 割込み番号 */ 		
	.long  212 											

	.align 2                       							
__kernel_default_int_handler_entry_213:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_213,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_213,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_213:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_213:                     /* 割込み番号 */ 		
	.long  213 											

	.align 2                       							
__kernel_default_int_handler_entry_214:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_214,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_214,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_214:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_214:                     /* 割込み番号 */ 		
	.long  214 											

	.align 2                       							
__kernel_default_int_handler_entry_215:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_215,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_215,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_215:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_215:                     /* 割込み番号 */ 		
	.long  215 											

	.align 2                       							
__kernel_default_int_handler_entry_216:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_216,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_216,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_216:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_216:                     /* 割込み番号 */ 		
	.long  216 											

	.align 2                       							
__kernel_default_int_handler_entry_217:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_217,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_217,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_217:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_217:                     /* 割込み番号 */ 		
	.long  217 											

	.align 2                       							
__kernel_default_int_handler_entry_218:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_218,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_218,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_218:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_218:                     /* 割込み番号 */ 		
	.long  218 											

	.align 2                       							
__kernel_default_int_handler_entry_219:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_219,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_219,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_219:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_219:                     /* 割込み番号 */ 		
	.long  219 											

	.align 2                       							
__kernel_default_int_handler_entry_220:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_220,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_220,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_220:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_220:                     /* 割込み番号 */ 		
	.long  220 											

	.align 2                       							
__kernel_default_int_handler_entry_221:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_221,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_221,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_221:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_221:                     /* 割込み番号 */ 		
	.long  221 											

	.align 2                       							
__kernel_default_int_handler_entry_222:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_222,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_222,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_222:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_222:                     /* 割込み番号 */ 		
	.long  222 											

	.align 2                       							
__kernel_default_int_handler_entry_223:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_223,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_223,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_223:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_223:                     /* 割込み番号 */ 		
	.long  223 											

	.align 2                       							
__kernel_default_int_handler_entry_224:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_224,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_224,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_224:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_224:                     /* 割込み番号 */ 		
	.long  224 											

	.align 2                       							
__kernel_default_int_handler_entry_225:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_225,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_225,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_225:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_225:                     /* 割込み番号 */ 		
	.long  225 											

	.align 2                       							
__kernel_default_int_handler_entry_226:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_226,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_226,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_226:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_226:                     /* 割込み番号 */ 		
	.long  226 											

	.align 2                       							
__kernel_default_int_handler_entry_227:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_227,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_227,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_227:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_227:                     /* 割込み番号 */ 		
	.long  227 											

	.align 2                       							
__kernel_default_int_handler_entry_228:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_228,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_228,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_228:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_228:                     /* 割込み番号 */ 		
	.long  228 											

	.align 2                       							
__kernel_default_int_handler_entry_229:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_229,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_229,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_229:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_229:                     /* 割込み番号 */ 		
	.long  229 											

	.align 2                       							
__kernel_default_int_handler_entry_230:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_230,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_230,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_230:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_230:                     /* 割込み番号 */ 		
	.long  230 											

	.align 2                       							
__kernel_default_int_handler_entry_231:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_231,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_231,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_231:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_231:                     /* 割込み番号 */ 		
	.long  231 											

	.align 2                       							
__kernel_default_int_handler_entry_232:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_232,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_232,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_232:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_232:                     /* 割込み番号 */ 		
	.long  232 											

	.align 2                       							
__kernel_default_int_handler_entry_233:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_233,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_233,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_233:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_233:                     /* 割込み番号 */ 		
	.long  233 											

	.align 2                       							
__kernel_default_int_handler_entry_234:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_234,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_234,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_234:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_234:                     /* 割込み番号 */ 		
	.long  234 											

	.align 2                       							
__kernel_default_int_handler_entry_235:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_235,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_235,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_235:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_235:                     /* 割込み番号 */ 		
	.long  235 											

	.align 2                       							
__kernel_default_int_handler_entry_236:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_236,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_236,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_236:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_236:                     /* 割込み番号 */ 		
	.long  236 											

	.align 2                       							
__kernel_default_int_handler_entry_237:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_237,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_237,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_237:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_237:                     /* 割込み番号 */ 		
	.long  237 											

	.global __kernel__kernel_inthdr_238_238											
	.align 2                       							
__kernel__kernel_inthdr_238_238:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
	mov.l r5,@-r15											
	mov.l r4,@-r15											
#endif /* USE_BANKED_REG */   								
	stc   sr,r7								/* SRの保存 */ 	
	mov.l _iipm_disall___kernel__kernel_inthdr_238_238,r6							
	ldc	  r6,sr								/* 全割込み禁止 */ 
		 /* 共有割込み入口処理 */    	
	mov.l _common_routine___kernel__kernel_inthdr_238_238,r4 						
		 /* 割込みハンドラの先頭アドレス */ 
	mov.l _c_routine___kernel__kernel_inthdr_238_238,r6     						
	mov.l _inhno___kernel__kernel_inthdr_238_238,r5					/* 割込み番号 */ 
	jmp	  @r4												
	 nop													
	.align 2												
		 /* 割込み禁止用マスク */ 			
_iipm_disall___kernel__kernel_inthdr_238_238:										
		 /* ipm以外のビットはゼロで良い */ 	
	.long  __kernel_iipm_disall								
_c_routine___kernel__kernel_inthdr_238_238:/* 割込みハンドラの先頭アドレス */				
	.long  __kernel_inthdr_238         					
		 /* cpu_support.S内の分岐先アドレス */			
_common_routine___kernel__kernel_inthdr_238_238: 									
	.long  __kernel_interrupt_entry							
_inhno___kernel__kernel_inthdr_238_238:							/* 割込み番号	*/	
	.long  238 											


	.global __kernel__kernel_inthdr_239_239											
	.align 2                       							
__kernel__kernel_inthdr_239_239:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
	mov.l r5,@-r15											
	mov.l r4,@-r15											
#endif /* USE_BANKED_REG */   								
	stc   sr,r7								/* SRの保存 */ 	
	mov.l _iipm_disall___kernel__kernel_inthdr_239_239,r6							
	ldc	  r6,sr								/* 全割込み禁止 */ 
		 /* 共有割込み入口処理 */    	
	mov.l _common_routine___kernel__kernel_inthdr_239_239,r4 						
		 /* 割込みハンドラの先頭アドレス */ 
	mov.l _c_routine___kernel__kernel_inthdr_239_239,r6     						
	mov.l _inhno___kernel__kernel_inthdr_239_239,r5					/* 割込み番号 */ 
	jmp	  @r4												
	 nop													
	.align 2												
		 /* 割込み禁止用マスク */ 			
_iipm_disall___kernel__kernel_inthdr_239_239:										
		 /* ipm以外のビットはゼロで良い */ 	
	.long  __kernel_iipm_disall								
_c_routine___kernel__kernel_inthdr_239_239:/* 割込みハンドラの先頭アドレス */				
	.long  __kernel_inthdr_239         					
		 /* cpu_support.S内の分岐先アドレス */			
_common_routine___kernel__kernel_inthdr_239_239: 									
	.long  __kernel_interrupt_entry							
_inhno___kernel__kernel_inthdr_239_239:							/* 割込み番号	*/	
	.long  239 											


	.align 2                       							
__kernel_default_int_handler_entry_240:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_240,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_240,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_240:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_240:                     /* 割込み番号 */ 		
	.long  240 											

	.align 2                       							
__kernel_default_int_handler_entry_241:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_241,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_241,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_241:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_241:                     /* 割込み番号 */ 		
	.long  241 											

	.align 2                       							
__kernel_default_int_handler_entry_242:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_242,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_242,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_242:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_242:                     /* 割込み番号 */ 		
	.long  242 											

	.align 2                       							
__kernel_default_int_handler_entry_243:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_243,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_243,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_243:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_243:                     /* 割込み番号 */ 		
	.long  243 											

	.align 2                       							
__kernel_default_int_handler_entry_244:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_244,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_244,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_244:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_244:                     /* 割込み番号 */ 		
	.long  244 											

	.align 2                       							
__kernel_default_int_handler_entry_245:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_245,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_245,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_245:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_245:                     /* 割込み番号 */ 		
	.long  245 											

	.align 2                       							
__kernel_default_int_handler_entry_246:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_246,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_246,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_246:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_246:                     /* 割込み番号 */ 		
	.long  246 											

	.align 2                       							
__kernel_default_int_handler_entry_247:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_247,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_247,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_247:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_247:                     /* 割込み番号 */ 		
	.long  247 											

	.align 2                       							
__kernel_default_int_handler_entry_248:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_248,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_248,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_248:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_248:                     /* 割込み番号 */ 		
	.long  248 											

	.align 2                       							
__kernel_default_int_handler_entry_249:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_249,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_249,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_249:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_249:                     /* 割込み番号 */ 		
	.long  249 											

	.align 2                       							
__kernel_default_int_handler_entry_250:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_250,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_250,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_250:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_250:                     /* 割込み番号 */ 		
	.long  250 											

	.align 2                       							
__kernel_default_int_handler_entry_251:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_251,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_251,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_251:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_251:                     /* 割込み番号 */ 		
	.long  251 											

	.align 2                       							
__kernel_default_int_handler_entry_252:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_252,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_252,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_252:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_252:                     /* 割込み番号 */ 		
	.long  252 											

	.align 2                       							
__kernel_default_int_handler_entry_253:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_253,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_253,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_253:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_253:                     /* 割込み番号 */ 		
	.long  253 											

	.align 2                       							
__kernel_default_int_handler_entry_254:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_254,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_254,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_254:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_254:                     /* 割込み番号 */ 		
	.long  254 											

	.align 2                       							
__kernel_default_int_handler_entry_255:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_255,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_255,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_255:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_255:                     /* 割込み番号 */ 		
	.long  255 											

	.align 2                       							
__kernel_default_int_handler_entry_256:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_256,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_256,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_256:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_256:                     /* 割込み番号 */ 		
	.long  256 											

	.align 2                       							
__kernel_default_int_handler_entry_257:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_257,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_257,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_257:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_257:                     /* 割込み番号 */ 		
	.long  257 											

	.align 2                       							
__kernel_default_int_handler_entry_258:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_258,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_258,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_258:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_258:                     /* 割込み番号 */ 		
	.long  258 											

	.align 2                       							
__kernel_default_int_handler_entry_259:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_259,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_259,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_259:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_259:                     /* 割込み番号 */ 		
	.long  259 											

	.align 2                       							
__kernel_default_int_handler_entry_260:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_260,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_260,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_260:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_260:                     /* 割込み番号 */ 		
	.long  260 											

	.align 2                       							
__kernel_default_int_handler_entry_261:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_261,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_261,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_261:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_261:                     /* 割込み番号 */ 		
	.long  261 											

	.align 2                       							
__kernel_default_int_handler_entry_262:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_262,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_262,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_262:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_262:                     /* 割込み番号 */ 		
	.long  262 											

	.align 2                       							
__kernel_default_int_handler_entry_263:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_263,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_263,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_263:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_263:                     /* 割込み番号 */ 		
	.long  263 											

	.align 2                       							
__kernel_default_int_handler_entry_264:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_264,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_264,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_264:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_264:                     /* 割込み番号 */ 		
	.long  264 											

	.align 2                       							
__kernel_default_int_handler_entry_265:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_265,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_265,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_265:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_265:                     /* 割込み番号 */ 		
	.long  265 											

	.align 2                       							
__kernel_default_int_handler_entry_266:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_266,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_266,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_266:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_266:                     /* 割込み番号 */ 		
	.long  266 											

	.align 2                       							
__kernel_default_int_handler_entry_267:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_267,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_267,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_267:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_267:                     /* 割込み番号 */ 		
	.long  267 											

	.align 2                       							
__kernel_default_int_handler_entry_268:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_268,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_268,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_268:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_268:                     /* 割込み番号 */ 		
	.long  268 											

	.align 2                       							
__kernel_default_int_handler_entry_269:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_269,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_269,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_269:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_269:                     /* 割込み番号 */ 		
	.long  269 											

	.align 2                       							
__kernel_default_int_handler_entry_270:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_270,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_270,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_270:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_270:                     /* 割込み番号 */ 		
	.long  270 											

	.align 2                       							
__kernel_default_int_handler_entry_271:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_271,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_271,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_271:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_271:                     /* 割込み番号 */ 		
	.long  271 											

	.align 2                       							
__kernel_default_int_handler_entry_272:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_272,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_272,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_272:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_272:                     /* 割込み番号 */ 		
	.long  272 											

	.align 2                       							
__kernel_default_int_handler_entry_273:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_273,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_273,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_273:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_273:                     /* 割込み番号 */ 		
	.long  273 											

	.align 2                       							
__kernel_default_int_handler_entry_274:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_274,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_274,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_274:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_274:                     /* 割込み番号 */ 		
	.long  274 											

	.align 2                       							
__kernel_default_int_handler_entry_275:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_275,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_275,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_275:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_275:                     /* 割込み番号 */ 		
	.long  275 											

	.align 2                       							
__kernel_default_int_handler_entry_276:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_276,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_276,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_276:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_276:                     /* 割込み番号 */ 		
	.long  276 											

	.align 2                       							
__kernel_default_int_handler_entry_277:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_277,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_277,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_277:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_277:                     /* 割込み番号 */ 		
	.long  277 											

	.align 2                       							
__kernel_default_int_handler_entry_278:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_278,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_278,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_278:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_278:                     /* 割込み番号 */ 		
	.long  278 											

	.align 2                       							
__kernel_default_int_handler_entry_279:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_279,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_279,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_279:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_279:                     /* 割込み番号 */ 		
	.long  279 											

	.align 2                       							
__kernel_default_int_handler_entry_280:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_280,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_280,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_280:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_280:                     /* 割込み番号 */ 		
	.long  280 											

	.align 2                       							
__kernel_default_int_handler_entry_281:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_281,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_281,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_281:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_281:                     /* 割込み番号 */ 		
	.long  281 											

	.align 2                       							
__kernel_default_int_handler_entry_282:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_282,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_282,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_282:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_282:                     /* 割込み番号 */ 		
	.long  282 											

	.align 2                       							
__kernel_default_int_handler_entry_283:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_283,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_283,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_283:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_283:                     /* 割込み番号 */ 		
	.long  283 											

	.align 2                       							
__kernel_default_int_handler_entry_284:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_284,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_284,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_284:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_284:                     /* 割込み番号 */ 		
	.long  284 											

	.align 2                       							
__kernel_default_int_handler_entry_285:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_285,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_285,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_285:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_285:                     /* 割込み番号 */ 		
	.long  285 											

	.align 2                       							
__kernel_default_int_handler_entry_286:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_286,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_286,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_286:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_286:                     /* 割込み番号 */ 		
	.long  286 											

	.align 2                       							
__kernel_default_int_handler_entry_287:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_287,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_287,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_287:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_287:                     /* 割込み番号 */ 		
	.long  287 											

	.align 2                       							
__kernel_default_int_handler_entry_288:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_288,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_288,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_288:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_288:                     /* 割込み番号 */ 		
	.long  288 											

	.align 2                       							
__kernel_default_int_handler_entry_289:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_289,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_289,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_289:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_289:                     /* 割込み番号 */ 		
	.long  289 											

	.align 2                       							
__kernel_default_int_handler_entry_290:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_290,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_290,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_290:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_290:                     /* 割込み番号 */ 		
	.long  290 											

	.align 2                       							
__kernel_default_int_handler_entry_291:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_291,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_291,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_291:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_291:                     /* 割込み番号 */ 		
	.long  291 											

	.align 2                       							
__kernel_default_int_handler_entry_292:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_292,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_292,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_292:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_292:                     /* 割込み番号 */ 		
	.long  292 											

	.align 2                       							
__kernel_default_int_handler_entry_293:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_293,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_293,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_293:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_293:                     /* 割込み番号 */ 		
	.long  293 											

	.align 2                       							
__kernel_default_int_handler_entry_294:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_294,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_294,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_294:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_294:                     /* 割込み番号 */ 		
	.long  294 											

	.align 2                       							
__kernel_default_int_handler_entry_296:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_296,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_296,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_296:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_296:                     /* 割込み番号 */ 		
	.long  296 											

	.align 2                       							
__kernel_default_int_handler_entry_297:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_297,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_297,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_297:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_297:                     /* 割込み番号 */ 		
	.long  297 											

	.align 2                       							
__kernel_default_int_handler_entry_298:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_298,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_298,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_298:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_298:                     /* 割込み番号 */ 		
	.long  298 											

	.align 2                       							
__kernel_default_int_handler_entry_299:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_299,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_299,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_299:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_299:                     /* 割込み番号 */ 		
	.long  299 											

	.align 2                       							
__kernel_default_int_handler_entry_300:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_300,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_300,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_300:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_300:                     /* 割込み番号 */ 		
	.long  300 											

	.align 2                       							
__kernel_default_int_handler_entry_301:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_301,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_301,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_301:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_301:                     /* 割込み番号 */ 		
	.long  301 											

	.align 2                       							
__kernel_default_int_handler_entry_302:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_302,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_302,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_302:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_302:                     /* 割込み番号 */ 		
	.long  302 											

	.align 2                       							
__kernel_default_int_handler_entry_303:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_303,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_303,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_303:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_303:                     /* 割込み番号 */ 		
	.long  303 											

	.align 2                       							
__kernel_default_int_handler_entry_304:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_304,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_304,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_304:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_304:                     /* 割込み番号 */ 		
	.long  304 											

	.align 2                       							
__kernel_default_int_handler_entry_305:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_305,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_305,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_305:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_305:                     /* 割込み番号 */ 		
	.long  305 											

	.align 2                       							
__kernel_default_int_handler_entry_306:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_306,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_306,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_306:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_306:                     /* 割込み番号 */ 		
	.long  306 											

	.align 2                       							
__kernel_default_int_handler_entry_307:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_307,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_307,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_307:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_307:                     /* 割込み番号 */ 		
	.long  307 											

	.align 2                       							
__kernel_default_int_handler_entry_308:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_308,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_308,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_308:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_308:                     /* 割込み番号 */ 		
	.long  308 											

	.align 2                       							
__kernel_default_int_handler_entry_310:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_310,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_310,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_310:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_310:                     /* 割込み番号 */ 		
	.long  310 											

	.align 2                       							
__kernel_default_int_handler_entry_311:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_311,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_311,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_311:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_311:                     /* 割込み番号 */ 		
	.long  311 											

	.align 2                       							
__kernel_default_int_handler_entry_312:													
#ifndef USE_BANKED_REG    									
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
#endif /* USE_BANKED_REG */   								
							/* cpu_support.S内の分岐先アドレス	*/ 	
	mov.l _default_int_handler_entry_asm___kernel_default_int_handler_entry_312,r7 		
	mov.l _inhno___kernel_default_int_handler_entry_312,r6				/* 割込み番号 */	
	jmp	  @r7                        						
	 nop						 	 						
	.align 2						 						
		/* cpu_support.S内の分岐先アドレス	*/ 	
_default_int_handler_entry_asm___kernel_default_int_handler_entry_312:						
	.long  __kernel_default_int_handler_entry				
_inhno___kernel_default_int_handler_entry_312:                     /* 割込み番号 */ 		
	.long  312 											
/*															
 *  CPU例外ハンドラの出入口処理								
 */															

.section .vector_entry,"xa"  							

	.align 2                           						
__kernel_exc_entry_4:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_4,r7			
	jmp	  @r7                        						
	 mov  #4,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_4:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_6:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_6,r7			
	jmp	  @r7                        						
	 mov  #6,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_6:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                       							
__kernel_cpuexc_handler_CPUEXC1:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 											
	mov.l r6,@-r15											
	mov.l r5,@-r15											
	mov.l r4,@-r15											
	stc   sr,r7								/* SRの保存 */	
	mov.l _iipm_disall___kernel_cpuexc_handler_CPUEXC1,r6							
	ldc	  r6,sr								/* 全割込み禁止 */ 
		 /* 共有CPU例外入口処理 */ 			
	mov.l _common_routine___kernel_cpuexc_handler_CPUEXC1,r4 						
		 /* ベクタ番号 */    					
	mov.l _vectorno___kernel_cpuexc_handler_CPUEXC1,r5       						
		 /* CPU例外ハンドラの先頭アドレス */ 	
	mov.l _c_routine___kernel_cpuexc_handler_CPUEXC1,r6      						
	jmp	  @r4												
	 nop													
	.align 2												
_iipm_disall___kernel_cpuexc_handler_CPUEXC1:			/* 割込み禁止用マスク */ 	
		 /* ipm以外のビットはゼロで良い */ 	
	.long  __kernel_iipm_disall								
		 /* CPU例外ハンドラの先頭アドレス */ 	
_c_routine___kernel_cpuexc_handler_CPUEXC1:											
	.long  _cpuexc_handler         					
_vectorno___kernel_cpuexc_handler_CPUEXC1:		/* ベクタ番号 */ 					
	.long  9                      					
		 /* cpu_support.S内の分岐先アドレス */ 
_common_routine___kernel_cpuexc_handler_CPUEXC1:									
	.long  __kernel_exception_entry        					


	.align 2                           						
__kernel_exc_entry_10:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_10,r7			
	jmp	  @r7                        						
	 mov  #10,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_10:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_12:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_12,r7			
	jmp	  @r7                        						
	 mov  #12,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_12:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_14:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_14,r7			
	jmp	  @r7                        						
	 mov  #14,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_14:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_15:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_15,r7			
	jmp	  @r7                        						
	 mov  #15,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_15:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_16:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_16,r7			
	jmp	  @r7                        						
	 mov  #16,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_16:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_17:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_17,r7			
	jmp	  @r7                        						
	 mov  #17,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_17:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_18:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_18,r7			
	jmp	  @r7                        						
	 mov  #18,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_18:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_32:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_32,r7			
	jmp	  @r7                        						
	 mov  #32,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_32:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_33:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_33,r7			
	jmp	  @r7                        						
	 mov  #33,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_33:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_34:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_34,r7			
	jmp	  @r7                        						
	 mov  #34,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_34:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_35:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_35,r7			
	jmp	  @r7                        						
	 mov  #35,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_35:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_36:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_36,r7			
	jmp	  @r7                        						
	 mov  #36,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_36:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_37:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_37,r7			
	jmp	  @r7                        						
	 mov  #37,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_37:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_38:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_38,r7			
	jmp	  @r7                        						
	 mov  #38,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_38:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_39:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_39,r7			
	jmp	  @r7                        						
	 mov  #39,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_39:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_40:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_40,r7			
	jmp	  @r7                        						
	 mov  #40,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_40:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_41:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_41,r7			
	jmp	  @r7                        						
	 mov  #41,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_41:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_42:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_42,r7			
	jmp	  @r7                        						
	 mov  #42,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_42:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_43:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_43,r7			
	jmp	  @r7                        						
	 mov  #43,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_43:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_44:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_44,r7			
	jmp	  @r7                        						
	 mov  #44,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_44:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_45:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_45,r7			
	jmp	  @r7                        						
	 mov  #45,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_45:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_46:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_46,r7			
	jmp	  @r7                        						
	 mov  #46,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_46:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_47:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_47,r7			
	jmp	  @r7                        						
	 mov  #47,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_47:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_48:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_48,r7			
	jmp	  @r7                        						
	 mov  #48,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_48:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_49:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_49,r7			
	jmp	  @r7                        						
	 mov  #49,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_49:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_50:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_50,r7			
	jmp	  @r7                        						
	 mov  #50,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_50:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_51:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_51,r7			
	jmp	  @r7                        						
	 mov  #51,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_51:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_52:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_52,r7			
	jmp	  @r7                        						
	 mov  #52,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_52:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_53:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_53,r7			
	jmp	  @r7                        						
	 mov  #53,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_53:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_54:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_54,r7			
	jmp	  @r7                        						
	 mov  #54,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_54:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_55:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_55,r7			
	jmp	  @r7                        						
	 mov  #55,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_55:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_56:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_56,r7			
	jmp	  @r7                        						
	 mov  #56,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_56:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_57:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_57,r7			
	jmp	  @r7                        						
	 mov  #57,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_57:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_58:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_58,r7			
	jmp	  @r7                        						
	 mov  #58,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_58:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_59:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_59,r7			
	jmp	  @r7                        						
	 mov  #59,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_59:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_60:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_60,r7			
	jmp	  @r7                        						
	 mov  #60,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_60:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_61:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_61,r7			
	jmp	  @r7                        						
	 mov  #61,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_61:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_62:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_62,r7			
	jmp	  @r7                        						
	 mov  #62,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_62:    					
	.long  __kernel_default_exc_handler_entry				


	.align 2                           						
__kernel_exc_entry_63:													
		 /*  必要最小限のレジスタをスタックに待避  */ 		
	mov.l r7,@-r15 			           						
	mov.l r6,@-r15											
			/* cpu_support.S内の分岐先アドレス */			
	mov.l _default_exc_handler_entry_asm___kernel_exc_entry_63,r7			
	jmp	  @r7                        						
	 mov  #63,r6				/* ベクタ番号 */    	

	.align 2						 						
	/* cpu_support.S内の分岐先アドレス */ 				
_default_exc_handler_entry_asm___kernel_exc_entry_63:    					
	.long  __kernel_default_exc_handler_entry				

/*															
 *  ベクタテーブル											
 */															

	.section .vector										
	.global __kernel_vectors								

__kernel_vectors:											
	.long	_start		/* 0 */								
	.long	0     		/* 1 */								
	.long	_start		/* 2 */								
	.long	0     		/* 3 */								

	/* CPU exception */										
	.long __kernel_exc_entry_4 /* 4 */
	.long _ext_ker /* 5 */
	.long __kernel_exc_entry_6 /* 6 */
	.long _ext_ker /* 7 */
	.long _ext_ker /* 8 */
	.long __kernel_cpuexc_handler_CPUEXC1 /* 9 */
	.long __kernel_exc_entry_10 /* 10 */
	.long __kernel_default_int_handler_entry_11 /* 11 */
	.long __kernel_exc_entry_12 /* 12 */
	.long _ext_ker /* 13 */
	.long __kernel_exc_entry_14 /* 14 */
	.long __kernel_exc_entry_15 /* 15 */
	.long __kernel_exc_entry_16 /* 16 */
	.long __kernel_exc_entry_17 /* 17 */
	.long __kernel_exc_entry_18 /* 18 */
	.long _ext_ker /* 19 */
	.long _ext_ker /* 20 */
	.long _ext_ker /* 21 */
	.long _ext_ker /* 22 */
	.long _ext_ker /* 23 */
	.long _ext_ker /* 24 */
	.long _ext_ker /* 25 */
	.long _ext_ker /* 26 */
	.long _ext_ker /* 27 */
	.long _ext_ker /* 28 */
	.long _ext_ker /* 29 */
	.long _ext_ker /* 30 */
	.long _ext_ker /* 31 */
	.long __kernel_exc_entry_32 /* 32 */
	.long __kernel_exc_entry_33 /* 33 */
	.long __kernel_exc_entry_34 /* 34 */
	.long __kernel_exc_entry_35 /* 35 */
	.long __kernel_exc_entry_36 /* 36 */
	.long __kernel_exc_entry_37 /* 37 */
	.long __kernel_exc_entry_38 /* 38 */
	.long __kernel_exc_entry_39 /* 39 */
	.long __kernel_exc_entry_40 /* 40 */
	.long __kernel_exc_entry_41 /* 41 */
	.long __kernel_exc_entry_42 /* 42 */
	.long __kernel_exc_entry_43 /* 43 */
	.long __kernel_exc_entry_44 /* 44 */
	.long __kernel_exc_entry_45 /* 45 */
	.long __kernel_exc_entry_46 /* 46 */
	.long __kernel_exc_entry_47 /* 47 */
	.long __kernel_exc_entry_48 /* 48 */
	.long __kernel_exc_entry_49 /* 49 */
	.long __kernel_exc_entry_50 /* 50 */
	.long __kernel_exc_entry_51 /* 51 */
	.long __kernel_exc_entry_52 /* 52 */
	.long __kernel_exc_entry_53 /* 53 */
	.long __kernel_exc_entry_54 /* 54 */
	.long __kernel_exc_entry_55 /* 55 */
	.long __kernel_exc_entry_56 /* 56 */
	.long __kernel_exc_entry_57 /* 57 */
	.long __kernel_exc_entry_58 /* 58 */
	.long __kernel_exc_entry_59 /* 59 */
	.long __kernel_exc_entry_60 /* 60 */
	.long __kernel_exc_entry_61 /* 61 */
	.long __kernel_exc_entry_62 /* 62 */
	.long __kernel_exc_entry_63 /* 63 */

	/* interrupt */											
	.long __kernel_default_int_handler_entry_64 /* 64 */
	.long __kernel_default_int_handler_entry_65 /* 65 */
	.long __kernel_default_int_handler_entry_66 /* 66 */
	.long __kernel_default_int_handler_entry_67 /* 67 */
	.long __kernel_default_int_handler_entry_68 /* 68 */
	.long __kernel_default_int_handler_entry_69 /* 69 */
	.long __kernel_default_int_handler_entry_70 /* 70 */
	.long __kernel_default_int_handler_entry_71 /* 71 */
	.long _ext_ker /* 72 */
	.long _ext_ker /* 73 */
	.long _ext_ker /* 74 */
	.long _ext_ker /* 75 */
	.long _ext_ker /* 76 */
	.long _ext_ker /* 77 */
	.long _ext_ker /* 78 */
	.long _ext_ker /* 79 */
	.long __kernel_default_int_handler_entry_80 /* 80 */
	.long __kernel_default_int_handler_entry_81 /* 81 */
	.long __kernel_default_int_handler_entry_82 /* 82 */
	.long __kernel_default_int_handler_entry_83 /* 83 */
	.long __kernel_default_int_handler_entry_84 /* 84 */
	.long __kernel_default_int_handler_entry_85 /* 85 */
	.long __kernel_default_int_handler_entry_86 /* 86 */
	.long __kernel_default_int_handler_entry_87 /* 87 */
	.long _ext_ker /* 88 */
	.long _ext_ker /* 89 */
	.long _ext_ker /* 90 */
	.long _ext_ker /* 91 */
	.long _ext_ker /* 92 */
	.long _ext_ker /* 93 */
	.long _ext_ker /* 94 */
	.long _ext_ker /* 95 */
	.long _ext_ker /* 96 */
	.long _ext_ker /* 97 */
	.long _ext_ker /* 98 */
	.long _ext_ker /* 99 */
	.long _ext_ker /* 100 */
	.long _ext_ker /* 101 */
	.long _ext_ker /* 102 */
	.long _ext_ker /* 103 */
	.long _ext_ker /* 104 */
	.long _ext_ker /* 105 */
	.long _ext_ker /* 106 */
	.long _ext_ker /* 107 */
	.long __kernel_default_int_handler_entry_108 /* 108 */
	.long __kernel_default_int_handler_entry_109 /* 109 */
	.long _ext_ker /* 110 */
	.long _ext_ker /* 111 */
	.long __kernel_default_int_handler_entry_112 /* 112 */
	.long __kernel_default_int_handler_entry_113 /* 113 */
	.long _ext_ker /* 114 */
	.long _ext_ker /* 115 */
	.long __kernel_default_int_handler_entry_116 /* 116 */
	.long __kernel_default_int_handler_entry_117 /* 117 */
	.long _ext_ker /* 118 */
	.long _ext_ker /* 119 */
	.long __kernel_default_int_handler_entry_120 /* 120 */
	.long __kernel_default_int_handler_entry_121 /* 121 */
	.long _ext_ker /* 122 */
	.long _ext_ker /* 123 */
	.long __kernel_default_int_handler_entry_124 /* 124 */
	.long __kernel_default_int_handler_entry_125 /* 125 */
	.long _ext_ker /* 126 */
	.long _ext_ker /* 127 */
	.long __kernel_default_int_handler_entry_128 /* 128 */
	.long __kernel_default_int_handler_entry_129 /* 129 */
	.long _ext_ker /* 130 */
	.long _ext_ker /* 131 */
	.long __kernel_default_int_handler_entry_132 /* 132 */
	.long __kernel_default_int_handler_entry_133 /* 133 */
	.long _ext_ker /* 134 */
	.long _ext_ker /* 135 */
	.long __kernel_default_int_handler_entry_136 /* 136 */
	.long __kernel_default_int_handler_entry_137 /* 137 */
	.long _ext_ker /* 138 */
	.long _ext_ker /* 139 */
	.long __kernel_default_int_handler_entry_140 /* 140 */
	.long __kernel_default_int_handler_entry_141 /* 141 */
	.long _ext_ker /* 142 */
	.long _ext_ker /* 143 */
	.long __kernel_default_int_handler_entry_144 /* 144 */
	.long __kernel_default_int_handler_entry_145 /* 145 */
	.long _ext_ker /* 146 */
	.long _ext_ker /* 147 */
	.long __kernel_default_int_handler_entry_148 /* 148 */
	.long __kernel_default_int_handler_entry_149 /* 149 */
	.long _ext_ker /* 150 */
	.long _ext_ker /* 151 */
	.long __kernel_default_int_handler_entry_152 /* 152 */
	.long __kernel_default_int_handler_entry_153 /* 153 */
	.long _ext_ker /* 154 */
	.long _ext_ker /* 155 */
	.long __kernel_default_int_handler_entry_156 /* 156 */
	.long __kernel_default_int_handler_entry_157 /* 157 */
	.long _ext_ker /* 158 */
	.long _ext_ker /* 159 */
	.long __kernel_default_int_handler_entry_160 /* 160 */
	.long __kernel_default_int_handler_entry_161 /* 161 */
	.long _ext_ker /* 162 */
	.long _ext_ker /* 163 */
	.long __kernel_default_int_handler_entry_164 /* 164 */
	.long __kernel_default_int_handler_entry_165 /* 165 */
	.long _ext_ker /* 166 */
	.long _ext_ker /* 167 */
	.long __kernel_default_int_handler_entry_168 /* 168 */
	.long __kernel_default_int_handler_entry_169 /* 169 */
	.long __kernel_default_int_handler_entry_170 /* 170 */
	.long __kernel_default_int_handler_entry_171 /* 171 */
	.long __kernel_default_int_handler_entry_172 /* 172 */
	.long __kernel_default_int_handler_entry_173 /* 173 */
	.long __kernel_default_int_handler_entry_174 /* 174 */
	.long __kernel_target_timer_handler_INHNO_TIMER /* 175 */
	.long __kernel_default_int_handler_entry_176 /* 176 */
	.long __kernel_default_int_handler_entry_177 /* 177 */
	.long __kernel_default_int_handler_entry_178 /* 178 */
	.long __kernel_default_int_handler_entry_179 /* 179 */
	.long __kernel_default_int_handler_entry_180 /* 180 */
	.long __kernel_default_int_handler_entry_181 /* 181 */
	.long __kernel_default_int_handler_entry_182 /* 182 */
	.long __kernel_default_int_handler_entry_183 /* 183 */
	.long __kernel_default_int_handler_entry_184 /* 184 */
	.long __kernel_default_int_handler_entry_185 /* 185 */
	.long __kernel_default_int_handler_entry_186 /* 186 */
	.long __kernel_default_int_handler_entry_187 /* 187 */
	.long __kernel_default_int_handler_entry_188 /* 188 */
	.long __kernel_default_int_handler_entry_189 /* 189 */
	.long __kernel_default_int_handler_entry_190 /* 190 */
	.long __kernel_default_int_handler_entry_191 /* 191 */
	.long __kernel_default_int_handler_entry_192 /* 192 */
	.long __kernel_default_int_handler_entry_193 /* 193 */
	.long __kernel_default_int_handler_entry_194 /* 194 */
	.long __kernel_default_int_handler_entry_195 /* 195 */
	.long __kernel_default_int_handler_entry_196 /* 196 */
	.long __kernel_default_int_handler_entry_197 /* 197 */
	.long __kernel_default_int_handler_entry_198 /* 198 */
	.long __kernel_default_int_handler_entry_199 /* 199 */
	.long __kernel_default_int_handler_entry_200 /* 200 */
	.long __kernel_default_int_handler_entry_201 /* 201 */
	.long __kernel_default_int_handler_entry_202 /* 202 */
	.long __kernel_default_int_handler_entry_203 /* 203 */
	.long __kernel_default_int_handler_entry_204 /* 204 */
	.long __kernel_default_int_handler_entry_205 /* 205 */
	.long __kernel_default_int_handler_entry_206 /* 206 */
	.long __kernel_default_int_handler_entry_207 /* 207 */
	.long __kernel_default_int_handler_entry_208 /* 208 */
	.long __kernel_default_int_handler_entry_209 /* 209 */
	.long __kernel_default_int_handler_entry_210 /* 210 */
	.long __kernel_default_int_handler_entry_211 /* 211 */
	.long __kernel_default_int_handler_entry_212 /* 212 */
	.long __kernel_default_int_handler_entry_213 /* 213 */
	.long __kernel_default_int_handler_entry_214 /* 214 */
	.long __kernel_default_int_handler_entry_215 /* 215 */
	.long __kernel_default_int_handler_entry_216 /* 216 */
	.long __kernel_default_int_handler_entry_217 /* 217 */
	.long __kernel_default_int_handler_entry_218 /* 218 */
	.long __kernel_default_int_handler_entry_219 /* 219 */
	.long __kernel_default_int_handler_entry_220 /* 220 */
	.long __kernel_default_int_handler_entry_221 /* 221 */
	.long __kernel_default_int_handler_entry_222 /* 222 */
	.long __kernel_default_int_handler_entry_223 /* 223 */
	.long __kernel_default_int_handler_entry_224 /* 224 */
	.long __kernel_default_int_handler_entry_225 /* 225 */
	.long __kernel_default_int_handler_entry_226 /* 226 */
	.long __kernel_default_int_handler_entry_227 /* 227 */
	.long __kernel_default_int_handler_entry_228 /* 228 */
	.long __kernel_default_int_handler_entry_229 /* 229 */
	.long __kernel_default_int_handler_entry_230 /* 230 */
	.long __kernel_default_int_handler_entry_231 /* 231 */
	.long __kernel_default_int_handler_entry_232 /* 232 */
	.long __kernel_default_int_handler_entry_233 /* 233 */
	.long __kernel_default_int_handler_entry_234 /* 234 */
	.long __kernel_default_int_handler_entry_235 /* 235 */
	.long __kernel_default_int_handler_entry_236 /* 236 */
	.long __kernel_default_int_handler_entry_237 /* 237 */
	.long __kernel__kernel_inthdr_238_238 /* 238 */
	.long __kernel__kernel_inthdr_239_239 /* 239 */
	.long __kernel_default_int_handler_entry_240 /* 240 */
	.long __kernel_default_int_handler_entry_241 /* 241 */
	.long __kernel_default_int_handler_entry_242 /* 242 */
	.long __kernel_default_int_handler_entry_243 /* 243 */
	.long __kernel_default_int_handler_entry_244 /* 244 */
	.long __kernel_default_int_handler_entry_245 /* 245 */
	.long __kernel_default_int_handler_entry_246 /* 246 */
	.long __kernel_default_int_handler_entry_247 /* 247 */
	.long __kernel_default_int_handler_entry_248 /* 248 */
	.long __kernel_default_int_handler_entry_249 /* 249 */
	.long __kernel_default_int_handler_entry_250 /* 250 */
	.long __kernel_default_int_handler_entry_251 /* 251 */
	.long __kernel_default_int_handler_entry_252 /* 252 */
	.long __kernel_default_int_handler_entry_253 /* 253 */
	.long __kernel_default_int_handler_entry_254 /* 254 */
	.long __kernel_default_int_handler_entry_255 /* 255 */
	.long __kernel_default_int_handler_entry_256 /* 256 */
	.long __kernel_default_int_handler_entry_257 /* 257 */
	.long __kernel_default_int_handler_entry_258 /* 258 */
	.long __kernel_default_int_handler_entry_259 /* 259 */
	.long __kernel_default_int_handler_entry_260 /* 260 */
	.long __kernel_default_int_handler_entry_261 /* 261 */
	.long __kernel_default_int_handler_entry_262 /* 262 */
	.long __kernel_default_int_handler_entry_263 /* 263 */
	.long __kernel_default_int_handler_entry_264 /* 264 */
	.long __kernel_default_int_handler_entry_265 /* 265 */
	.long __kernel_default_int_handler_entry_266 /* 266 */
	.long __kernel_default_int_handler_entry_267 /* 267 */
	.long __kernel_default_int_handler_entry_268 /* 268 */
	.long __kernel_default_int_handler_entry_269 /* 269 */
	.long __kernel_default_int_handler_entry_270 /* 270 */
	.long __kernel_default_int_handler_entry_271 /* 271 */
	.long __kernel_default_int_handler_entry_272 /* 272 */
	.long __kernel_default_int_handler_entry_273 /* 273 */
	.long __kernel_default_int_handler_entry_274 /* 274 */
	.long __kernel_default_int_handler_entry_275 /* 275 */
	.long __kernel_default_int_handler_entry_276 /* 276 */
	.long __kernel_default_int_handler_entry_277 /* 277 */
	.long __kernel_default_int_handler_entry_278 /* 278 */
	.long __kernel_default_int_handler_entry_279 /* 279 */
	.long __kernel_default_int_handler_entry_280 /* 280 */
	.long __kernel_default_int_handler_entry_281 /* 281 */
	.long __kernel_default_int_handler_entry_282 /* 282 */
	.long __kernel_default_int_handler_entry_283 /* 283 */
	.long __kernel_default_int_handler_entry_284 /* 284 */
	.long __kernel_default_int_handler_entry_285 /* 285 */
	.long __kernel_default_int_handler_entry_286 /* 286 */
	.long __kernel_default_int_handler_entry_287 /* 287 */
	.long __kernel_default_int_handler_entry_288 /* 288 */
	.long __kernel_default_int_handler_entry_289 /* 289 */
	.long __kernel_default_int_handler_entry_290 /* 290 */
	.long __kernel_default_int_handler_entry_291 /* 291 */
	.long __kernel_default_int_handler_entry_292 /* 292 */
	.long __kernel_default_int_handler_entry_293 /* 293 */
	.long __kernel_default_int_handler_entry_294 /* 294 */
	.long _ext_ker /* 295 */
	.long __kernel_default_int_handler_entry_296 /* 296 */
	.long __kernel_default_int_handler_entry_297 /* 297 */
	.long __kernel_default_int_handler_entry_298 /* 298 */
	.long __kernel_default_int_handler_entry_299 /* 299 */
	.long __kernel_default_int_handler_entry_300 /* 300 */
	.long __kernel_default_int_handler_entry_301 /* 301 */
	.long __kernel_default_int_handler_entry_302 /* 302 */
	.long __kernel_default_int_handler_entry_303 /* 303 */
	.long __kernel_default_int_handler_entry_304 /* 304 */
	.long __kernel_default_int_handler_entry_305 /* 305 */
	.long __kernel_default_int_handler_entry_306 /* 306 */
	.long __kernel_default_int_handler_entry_307 /* 307 */
	.long __kernel_default_int_handler_entry_308 /* 308 */
	.long _ext_ker /* 309 */
	.long __kernel_default_int_handler_entry_310 /* 310 */
	.long __kernel_default_int_handler_entry_311 /* 311 */
	.long __kernel_default_int_handler_entry_312 /* 312 */

