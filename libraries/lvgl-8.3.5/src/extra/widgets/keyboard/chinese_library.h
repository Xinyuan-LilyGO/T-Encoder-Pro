/**********************
 *  STATIC VARIABLES
 **********************/

#if LV_USE_ZH_KEYBOARD

struct PINYIN_initials {
    char * PINYIN;
    char * PINYIN_mp;
};

#if LV_ZH_KEYBOARD_MINI
/*Chinese Characters UTF-8*/
static char PINYIN_mp_a[] = {"啊阿"};
static char PINYIN_mp_ai[] = {"爱矮挨哎"};
static char PINYIN_mp_an[] = {"按安暗"};
static char PINYIN_mp_ang[] = {"昂"};
static char PINYIN_mp_ao[] = {"傲奥熬"};
static char PINYIN_mp_ba[] = {"把八吧爸"};
static char PINYIN_mp_bai[] = {"百白"};
static char PINYIN_mp_ban[] = {"半办班"};
static char PINYIN_mp_bang[] = {"帮棒绑"};
static char PINYIN_mp_bao[] = {"包抱报饱"};
static char PINYIN_mp_bei[] = {"被北倍杯背悲"};
static char PINYIN_mp_ben[] = {"本奔苯笨"};
static char PINYIN_mp_beng[] = {"蹦绷甭崩"};
static char PINYIN_mp_bi[] = {"比笔闭鼻碧必避逼"};
static char PINYIN_mp_bian[] = {"边变便"};
static char PINYIN_mp_biao[] = {"表标"};
static char PINYIN_mp_bie[] = {"别憋"};
static char PINYIN_mp_bin[] = {"宾彬"};
static char PINYIN_mp_bing[] = {"并病兵冰"};
static char PINYIN_mp_bo[] = {"波播泊博伯"};
static char PINYIN_mp_bu[] = {"不步"};
static char PINYIN_mp_ca[] = {"擦"};
static char PINYIN_mp_cai[] = {"猜才菜蔡"};
static char PINYIN_mp_can[] = {"蚕残掺参惨惭"};
static char PINYIN_mp_cang[] = {"藏仓"};
static char PINYIN_mp_cao[] = {"草操曹"};
static char PINYIN_mp_ce[] = {"册厕"};
static char PINYIN_mp_cen[] = {"参"};
static char PINYIN_mp_ceng[] = {"曾层"};
static char PINYIN_mp_cha[] = {"查插叉茶差"};
static char PINYIN_mp_chai[] = {"菜柴拆"};
static char PINYIN_mp_chan[] = {"产缠掺"};
static char PINYIN_mp_chang[] = {"长唱常场厂"};
static char PINYIN_mp_chao[] = {"抄超吵"};
static char PINYIN_mp_che[] = {"车"};
static char PINYIN_mp_chen[] = {"趁称陈"};
static char PINYIN_mp_cheng[] = {"成乘称城程"};
static char PINYIN_mp_chi[] = {"吃尺斥"};
static char PINYIN_mp_chong[] = {"冲重虫充"};
static char PINYIN_mp_chou[] = {"抽愁臭仇丑"};
static char PINYIN_mp_chu[] = {"出处初"};
static char PINYIN_mp_chuai[] = {"揣"};
static char PINYIN_mp_chuan[] = {"穿船传串川"};
static char PINYIN_mp_chuang[] = {"窗床闯创"};
static char PINYIN_mp_chui[] = {"吹垂炊"};
static char PINYIN_mp_chun[] = {"春唇"};
static char PINYIN_mp_chuo[] = {"戳绰"};
static char PINYIN_mp_ci[] = {"次此词"};
static char PINYIN_mp_cong[] = {"从葱匆聪"};
static char PINYIN_mp_cou[] = {"凑"};
static char PINYIN_mp_cu[] = {"粗醋"};
static char PINYIN_mp_cuan[] = {"窜"};
static char PINYIN_mp_cui[] = {"催脆摧"};
static char PINYIN_mp_cun[] = {"村寸存"};
static char PINYIN_mp_cuo[] = {"错搓挫"};
static char PINYIN_mp_da[] = {"大答达打搭"};
static char PINYIN_mp_dai[] = {"带代呆"};
static char PINYIN_mp_dan[] = {"但单蛋担胆淡丹"};
static char PINYIN_mp_dang[] = {"当党挡档荡"};
static char PINYIN_mp_dao[] = {"到道倒刀岛盗稻捣"};
static char PINYIN_mp_de[] = {"的地得德底"};
static char PINYIN_mp_dei[] = {"得"};
static char PINYIN_mp_deng[] = {"等灯邓登"};
static char PINYIN_mp_di[] = {"地第底低敌抵滴帝"};
static char PINYIN_mp_dia[] = {"嗲"};
static char PINYIN_mp_dian[] = {"点电店"};
static char PINYIN_mp_diao[] = {"掉钓叼吊"};
static char PINYIN_mp_die[] = {"爹跌"};
static char PINYIN_mp_ding[] = {"顶定盯订丁钉"};
static char PINYIN_mp_diu[] = {"丢"};
static char PINYIN_mp_dong[] = {"动东懂洞冻冬董"};
static char PINYIN_mp_dou[] = {"都斗豆逗陡抖"};
static char PINYIN_mp_du[] = {"读度毒渡堵独肚"};
static char PINYIN_mp_duan[] = {"段短断端"};
static char PINYIN_mp_dui[] = {"对队堆兑"};
static char PINYIN_mp_dun[] = {"吨顿蹲钝盾"};
static char PINYIN_mp_duo[] = {"多朵夺"};
static char PINYIN_mp_e[] = {"饿额鹅"};
static char PINYIN_mp_ei[] = {"诶"};
static char PINYIN_mp_en[] = {"恩嗯"};
static char PINYIN_mp_er[] = {"而二耳儿饵尔"};
static char PINYIN_mp_fa[] = {"发法罚伐乏筏阀"};
static char PINYIN_mp_fan[] = {"反饭翻番犯凡帆"};
static char PINYIN_mp_fang[] = {"放房防纺芳方访仿坊"};
static char PINYIN_mp_fei[] = {"非飞肥费肺废"};
static char PINYIN_mp_fen[] = {"分份芬粉坟奋"};
static char PINYIN_mp_feng[] = {"风封蜂丰"};
static char PINYIN_mp_fo[] = {"佛"};
static char PINYIN_mp_fou[] = {"否"};
static char PINYIN_mp_fu[] = {"扶浮富福负伏付复服附俯芙夫父"};
static char PINYIN_mp_ga[] = {"夹嘎"};
static char PINYIN_mp_gai[] = {"该改盖"};
static char PINYIN_mp_gan[] = {"赶干感"};
static char PINYIN_mp_gang[] = {"刚钢"};
static char PINYIN_mp_gao[] = {"高搞告羔"};
static char PINYIN_mp_ge[] = {"个各歌哥搁格阁隔革"};
static char PINYIN_mp_gei[] = {"给"};
static char PINYIN_mp_gen[] = {"跟根"};
static char PINYIN_mp_geng[] = {"更"};
static char PINYIN_mp_gong[] = {"工公功共弓巩"};
static char PINYIN_mp_gou[] = {"够沟狗钩勾"};
static char PINYIN_mp_gu[] = {"古股鼓谷故"};
static char PINYIN_mp_gua[] = {"挂刮瓜"};
static char PINYIN_mp_guai[] = {"怪拐"};
static char PINYIN_mp_guan[] = {"关管官观馆惯罐"};
static char PINYIN_mp_guang[] = {"光广逛"};
static char PINYIN_mp_gui[] = {"归贵鬼跪轨规"};
static char PINYIN_mp_gun[] = {"滚棍"};
static char PINYIN_mp_guo[] = {"过国果裹锅郭"};
static char PINYIN_mp_ha[] = {"哈蛤虾呵"};
static char PINYIN_mp_hai[] = {"还海害咳氦孩"};
static char PINYIN_mp_han[] = {"喊含汗寒汉旱"};
static char PINYIN_mp_hang[] = {"行巷航"};
static char PINYIN_mp_hao[] = {"好号浩"};
static char PINYIN_mp_he[] = {"和喝合河禾核何"};
static char PINYIN_mp_hei[] = {"黑嘿嗨"};
static char PINYIN_mp_hen[] = {"很狠恨"};
static char PINYIN_mp_heng[] = {"横恒哼"};
static char PINYIN_mp_hong[] = {"红轰哄虹洪"};
static char PINYIN_mp_hou[] = {"后厚吼喉"};
static char PINYIN_mp_hu[] = {"湖户呼虎"};
static char PINYIN_mp_hua[] = {"话花化画华划"};
static char PINYIN_mp_huai[] = {"坏怀"};
static char PINYIN_mp_huan[] = {"换还唤环患缓欢"};
static char PINYIN_mp_huang[] = {"黄慌晃"};
static char PINYIN_mp_hui[] = {"回会灰绘挥汇辉"};
static char PINYIN_mp_hun[] = {"混昏浑婚"};
static char PINYIN_mp_huo[] = {"或活火伙货"};
static char PINYIN_mp_ji[] = {"几及急既即机鸡积记级极计"};
static char PINYIN_mp_jia[] = {"家加假价架甲佳夹嘉"};
static char PINYIN_mp_jian[] = {"见件减尖间贱肩兼建检健艰荐剑"};
static char PINYIN_mp_jiang[] = {"将讲江奖降浆姜蒋"};
static char PINYIN_mp_jiao[] = {"叫脚交角教觉焦"};
static char PINYIN_mp_jie[] = {"接节街借皆截解界结届姐"};
static char PINYIN_mp_jin[] = {"进近今仅紧金斤"};
static char PINYIN_mp_jing[] = {"竟静井惊经镜京净敬精景"};
static char PINYIN_mp_jiong[] = {"窘炅"};
static char PINYIN_mp_jiu[] = {"就九酒旧久揪救纠舅"};
static char PINYIN_mp_ju[] = {"句举巨局具"};
static char PINYIN_mp_juan[] = {"卷倦捐眷"};
static char PINYIN_mp_jue[] = {"决绝觉角爵"};
static char PINYIN_mp_jun[] = {"军君均菌俊匀"};
static char PINYIN_mp_ka[] = {"卡喀咯咖胩咔佧"};
static char PINYIN_mp_kai[] = {"开凯慨楷"};
static char PINYIN_mp_kan[] = {"看砍刊坎"};
static char PINYIN_mp_kang[] = {"抗炕扛"};
static char PINYIN_mp_kao[] = {"靠考烤"};
static char PINYIN_mp_ke[] = {"咳可克棵科颗刻课客壳渴"};
static char PINYIN_mp_ken[] = {"肯啃恳垦"};
static char PINYIN_mp_keng[] = {"坑吭"};
static char PINYIN_mp_kong[] = {"空孔控恐"};
static char PINYIN_mp_kou[] = {"口扣抠"};
static char PINYIN_mp_ku[] = {"哭库苦枯"};
static char PINYIN_mp_kua[] = {"跨垮挎"};
static char PINYIN_mp_kuai[] = {"快块筷会"};
static char PINYIN_mp_kuan[] = {"宽款"};
static char PINYIN_mp_kuang[] = {"矿筐狂框况旷匡"};
static char PINYIN_mp_kui[] = {"亏愧奎窥"};
static char PINYIN_mp_kun[] = {"捆困昆"};
static char PINYIN_mp_kuo[] = {"阔扩"};
static char PINYIN_mp_la[] = {"拉啦辣蜡腊"};
static char PINYIN_mp_lai[] = {"来赖莱"};
static char PINYIN_mp_lan[] = {"蓝兰烂拦"};
static char PINYIN_mp_lang[] = {"浪郎朗"};
static char PINYIN_mp_lao[] = {"老捞牢"};
static char PINYIN_mp_le[] = {"了乐勒嘞"};
static char PINYIN_mp_lei[] = {"类累泪雷垒勒擂蕾肋镭儡磊缧诔耒酹羸嫘檑嘞漯"};
static char PINYIN_mp_leng[] = {"冷棱楞愣"};
static char PINYIN_mp_li[] = {"里离力立李例哩理利梨厘礼历丽吏"};
static char PINYIN_mp_lia[] = {"俩"};
static char PINYIN_mp_lian[] = {"连联练莲恋脸炼链敛"};
static char PINYIN_mp_liang[] = {"两亮辆凉粮梁量良晾谅"};
static char PINYIN_mp_liao[] = {"了料撩辽僚"};
static char PINYIN_mp_lie[] = {"列裂猎劣烈咧"};
static char PINYIN_mp_lin[] = {"林临淋邻吝"};
static char PINYIN_mp_ling[] = {"另令领零铃玲灵岭"};
static char PINYIN_mp_liu[] = {"六流留刘柳"};
static char PINYIN_mp_lo[] = {"咯"};
static char PINYIN_mp_long[] = {"龙拢笼聋隆垄窿陇茏"};
static char PINYIN_mp_lou[] = {"楼搂漏陋露娄篓喽嵝"};
static char PINYIN_mp_lu[] = {"路露录鹿陆炉卢鲁卤芦颅"};
static char PINYIN_mp_luan[] = {"乱卵峦孪"};
static char PINYIN_mp_lun[] = {"论轮抡伦沦囵"};
static char PINYIN_mp_luo[] = {"落罗裸骡烙螺萝洛骆逻"};
static char PINYIN_mp_lv[] = {"绿率铝驴旅屡滤吕律"};
static char PINYIN_mp_lue[] = {"略掠"};
static char PINYIN_mp_ma[] = {"吗妈马嘛麻骂抹码玛蚂"};
static char PINYIN_mp_mai[] = {"买卖迈埋麦脉"};
static char PINYIN_mp_man[] = {"满慢瞒漫蛮蔓曼埋"};
static char PINYIN_mp_mang[] = {"忙芒盲莽茫氓"};
static char PINYIN_mp_mao[] = {"毛冒帽猫矛貌茂贸"};
static char PINYIN_mp_me[] = {"么麽"};
static char PINYIN_mp_mei[] = {"没每煤美酶妹枚霉玫"};
static char PINYIN_mp_men[] = {"门们"};
static char PINYIN_mp_meng[] = {"猛梦盟檬萌瞢"};
static char PINYIN_mp_mi[] = {"米密迷眯蜜谜觅秘弥幂"};
static char PINYIN_mp_mian[] = {"面棉免绵眠缅勉冕"};
static char PINYIN_mp_miao[] = {"秒苗庙妙描瞄"};
static char PINYIN_mp_mie[] = {"灭蔑咩"};
static char PINYIN_mp_min[] = {"民抿敏闽皿悯闵"};
static char PINYIN_mp_ming[] = {"名明命鸣"};
static char PINYIN_mp_miu[] = {"谬缪"};
static char PINYIN_mp_mo[] = {"摸磨抹末膜墨没莫默"};
static char PINYIN_mp_mou[] = {"某谋牟眸"};
static char PINYIN_mp_mu[] = {"木母亩幕目墓募慕睦沐"};
static char PINYIN_mp_na[] = {"那拿哪纳钠娜内"};
static char PINYIN_mp_nai[] = {"乃耐奶"};
static char PINYIN_mp_nan[] = {"难南男"};
static char PINYIN_mp_nang[] = {"囊"};
static char PINYIN_mp_nao[] = {"闹脑恼孬"};
static char PINYIN_mp_ne[] = {"呢哪那呐讷疒"};
static char PINYIN_mp_nei[] = {"内哪馁那"};
static char PINYIN_mp_nen[] = {"嫩恁"};
static char PINYIN_mp_neng[] = {"能"};
static char PINYIN_mp_ng[] = {"嗯"};
static char PINYIN_mp_ni[] = {"你泥拟腻逆呢"};
static char PINYIN_mp_nian[] = {"年念捻撵拈碾"};
static char PINYIN_mp_niang[] = {"娘酿"};
static char PINYIN_mp_niao[] = {"鸟尿溺"};
static char PINYIN_mp_nie[] = {"捏镍聂"};
static char PINYIN_mp_nin[] = {"您恁"};
static char PINYIN_mp_ning[] = {"拧凝宁柠狞"};
static char PINYIN_mp_niu[] = {"牛扭纽忸妞拗"};
static char PINYIN_mp_nong[] = {"弄浓农脓侬"};
static char PINYIN_mp_nou[] = {"耨"};
static char PINYIN_mp_nu[] = {"怒努奴"};
static char PINYIN_mp_nv[] = {"女"};
static char PINYIN_mp_nue[] = {"虐疟"};
static char PINYIN_mp_nuan[] = {"暖"};
static char PINYIN_mp_nuo[] = {"挪诺"};
static char PINYIN_mp_o[] = {"哦喔噢"};
static char PINYIN_mp_ou[] = {"偶欧藕鸥区"};
static char PINYIN_mp_pa[] = {"怕爬趴扒帕琶杷"};
static char PINYIN_mp_pai[] = {"派排拍牌迫"};
static char PINYIN_mp_pan[] = {"盘盼判攀畔潘"};
static char PINYIN_mp_pang[] = {"旁胖仿"};
static char PINYIN_mp_pao[] = {"跑抛炮泡刨"};
static char PINYIN_mp_pei[] = {"陪配赔胚佩培沛裴"};
static char PINYIN_mp_pen[] = {"喷盆"};
static char PINYIN_mp_peng[] = {"碰捧棚朋彭鹏"};
static char PINYIN_mp_pi[] = {"批皮披匹劈辟"};
static char PINYIN_mp_pian[] = {"片篇骗偏便扁翩"};
static char PINYIN_mp_piao[] = {"票飘漂瓢"};
static char PINYIN_mp_pie[] = {"瞥撇"};
static char PINYIN_mp_pin[] = {"品贫聘拼频"};
static char PINYIN_mp_ping[] = {"平凭瓶评屏乒萍苹"};
static char PINYIN_mp_po[] = {"破坡颇婆泼迫泊魄"};
static char PINYIN_mp_pou[] = {"剖"};
static char PINYIN_mp_pu[] = {"扑铺仆蒲"};
static char PINYIN_mp_qi[] = {"起其七气期齐妻骑汽"};
static char PINYIN_mp_qia[] = {"恰卡掐洽"};
static char PINYIN_mp_qian[] = {"前钱千牵浅签欠骞"};
static char PINYIN_mp_qiang[] = {"强枪墙抢腔"};
static char PINYIN_mp_qiao[] = {"桥敲巧悄俏窍雀乔侨"};
static char PINYIN_mp_qie[] = {"切且怯窃"};
static char PINYIN_mp_qin[] = {"亲琴寝"};
static char PINYIN_mp_qing[] = {"请轻清青倩"};
static char PINYIN_mp_qiong[] = {"穷琼"};
static char PINYIN_mp_qiu[] = {"求球秋丘仇邱"};
static char PINYIN_mp_qu[] = {"去取区娶"};
static char PINYIN_mp_quan[] = {"全权劝圈拳"};
static char PINYIN_mp_que[] = {"却缺确"};
static char PINYIN_mp_qui[] = {"鼽"};
static char PINYIN_mp_qun[] = {"群裙"};
static char PINYIN_mp_ran[] = {"染燃然冉髯苒蚺"};
static char PINYIN_mp_rang[] = {"让嚷"};
static char PINYIN_mp_rao[] = {"饶绕扰"};
static char PINYIN_mp_re[] = {"热"};
static char PINYIN_mp_ren[] = {"人任忍认刃仁"};
static char PINYIN_mp_reng[] = {"仍扔"};
static char PINYIN_mp_ri[] = {"日"};
static char PINYIN_mp_rong[] = {"容绒融溶"};
static char PINYIN_mp_rou[] = {"肉揉柔"};
static char PINYIN_mp_ru[] = {"如入汝茹乳"};
static char PINYIN_mp_ruan[] = {"软阮"};
static char PINYIN_mp_rui[] = {"瑞蕊锐"};
static char PINYIN_mp_run[] = {"闰润"};
static char PINYIN_mp_ruo[] = {"若弱"};
static char PINYIN_mp_sa[] = {"撒洒"};
static char PINYIN_mp_sai[] = {"塞腮"};
static char PINYIN_mp_san[] = {"三散伞"};
static char PINYIN_mp_sang[] = {"桑"};
static char PINYIN_mp_sao[] = {"扫嫂"};
static char PINYIN_mp_se[] = {"色涩"};
static char PINYIN_mp_sen[] = {"森"};
static char PINYIN_mp_seng[] = {"僧"};
static char PINYIN_mp_sha[] = {"杀沙啥纱"};
static char PINYIN_mp_shai[] = {"晒筛色"};
static char PINYIN_mp_shan[] = {"山闪衫善"};
static char PINYIN_mp_shang[] = {"上伤"};
static char PINYIN_mp_shao[] = {"少烧哨勺"};
static char PINYIN_mp_she[] = {"蛇设舌"};
static char PINYIN_mp_shei[] = {"谁"};
static char PINYIN_mp_shen[] = {"身伸深神"};
static char PINYIN_mp_sheng[] = {"声省生升"};
static char PINYIN_mp_shi[] = {"是使十时事室市石"};
static char PINYIN_mp_shou[] = {"手受收首守"};
static char PINYIN_mp_shu[] = {"书树数"};
static char PINYIN_mp_shua[] = {"耍"};
static char PINYIN_mp_shuai[] = {"摔甩帅"};
static char PINYIN_mp_shuan[] = {"栓"};
static char PINYIN_mp_shuang[] = {"双霜"};
static char PINYIN_mp_shui[] = {"水谁"};
static char PINYIN_mp_shun[] = {"顺瞬"};
static char PINYIN_mp_shuo[] = {"说"};
static char PINYIN_mp_si[] = {"四司"};
static char PINYIN_mp_song[] = {"送松"};
static char PINYIN_mp_sou[] = {"艘搜"};
static char PINYIN_mp_su[] = {"素速"};
static char PINYIN_mp_suan[] = {"酸算"};
static char PINYIN_mp_sui[] = {"岁随碎虽"};
static char PINYIN_mp_sun[] = {"孙损"};
static char PINYIN_mp_suo[] = {"所缩"};
static char PINYIN_mp_ta[] = {"他她它"};
static char PINYIN_mp_tai[] = {"太抬台"};
static char PINYIN_mp_tan[] = {"谈叹探"};
static char PINYIN_mp_tang[] = {"躺趟堂"};
static char PINYIN_mp_tao[] = {"套掏逃"};
static char PINYIN_mp_te[] = {"特忒"};
static char PINYIN_mp_teng[] = {"疼腾藤"};
static char PINYIN_mp_ti[] = {"提替体题"};
static char PINYIN_mp_tian[] = {"天田添"};
static char PINYIN_mp_tiao[] = {"条跳挑"};
static char PINYIN_mp_tie[] = {"铁贴"};
static char PINYIN_mp_ting[] = {"听霆"};
static char PINYIN_mp_tong[] = {"同通痛"};
static char PINYIN_mp_tou[] = {"头偷透"};
static char PINYIN_mp_tu[] = {"土图兔涂"};
static char PINYIN_mp_tuan[] = {"团湍"};
static char PINYIN_mp_tui[] = {"腿推"};
static char PINYIN_mp_tun[] = {"吞屯"};
static char PINYIN_mp_tuo[] = {"拖脱托"};
static char PINYIN_mp_wa[] = {"挖瓦蛙"};
static char PINYIN_mp_wai[] = {"外歪"};
static char PINYIN_mp_wan[] = {"完万晚"};
static char PINYIN_mp_wang[] = {"望忘王往"};
static char PINYIN_mp_wei[] = {"为位未围"};
static char PINYIN_mp_wen[] = {"问文闻稳温"};
static char PINYIN_mp_weng[] = {"翁嗡"};
static char PINYIN_mp_wo[] = {"我握窝"};
static char PINYIN_mp_wu[] = {"无五屋物舞"};
static char PINYIN_mp_xi[] = {"西洗细吸戏"};
static char PINYIN_mp_xia[] = {"下吓"};
static char PINYIN_mp_xian[] = {"先线县现"};
static char PINYIN_mp_xiang[] = {"想向象"};
static char PINYIN_mp_xiao[] = {"小笑消"};
static char PINYIN_mp_xie[] = {"写些血"};
static char PINYIN_mp_xin[] = {"新心欣信"};
static char PINYIN_mp_xing[] = {"行型形星兴"};
static char PINYIN_mp_xiong[] = {"雄凶兄"};
static char PINYIN_mp_xiu[] = {"修"};
static char PINYIN_mp_xu[] = {"许须需虚"};
static char PINYIN_mp_xuan[] = {"选悬"};
static char PINYIN_mp_xue[] = {"学雪"};
static char PINYIN_mp_xun[] = {"寻讯熏"};
static char PINYIN_mp_ya[] = {"呀压"};
static char PINYIN_mp_yan[] = {"眼烟沿盐言演"};
static char PINYIN_mp_yang[] = {"样养羊洋仰扬"};
static char PINYIN_mp_yao[] = {"要摇药咬"};
static char PINYIN_mp_ye[] = {"也夜业"};
static char PINYIN_mp_yi[] = {"一以已亿衣移依易医乙仪"};
static char PINYIN_mp_yin[] = {"因引印银音饮"};
static char PINYIN_mp_ying[] = {"应硬影营迎映"};
static char PINYIN_mp_yo[] = {"哟育唷"};
static char PINYIN_mp_yong[] = {"用涌永拥"};
static char PINYIN_mp_you[] = {"有又由右油游幼优友"};
static char PINYIN_mp_yu[] = {"与于欲鱼雨余遇语"};
static char PINYIN_mp_yuan[] = {"远员元"};
static char PINYIN_mp_yue[] = {"月越约"};
static char PINYIN_mp_yun[] = {"云运晕"};
static char PINYIN_mp_za[] = {"杂砸"};
static char PINYIN_mp_zai[] = {"在再"};
static char PINYIN_mp_zan[] = {"咱"};
static char PINYIN_mp_zang[] = {"脏"};
static char PINYIN_mp_zao[] = {"早造"};
static char PINYIN_mp_ze[] = {"则责"};
static char PINYIN_mp_zei[] = {"贼"};
static char PINYIN_mp_zen[] = {"怎谮"};
static char PINYIN_mp_zeng[] = {"增赠曾"};
static char PINYIN_mp_zha[] = {"扎炸渣闸"};
static char PINYIN_mp_zhai[] = {"摘窄"};
static char PINYIN_mp_zhan[] = {"站占战"};
static char PINYIN_mp_zhang[] = {"张章"};
static char PINYIN_mp_zhao[] = {"找着罩"};
static char PINYIN_mp_zhe[] = {"着这者折"};
static char PINYIN_mp_zhen[] = {"真阵镇针"};
static char PINYIN_mp_zheng[] = {"正整睁"};
static char PINYIN_mp_zhi[] = {"只之直知制指"};
static char PINYIN_mp_zhong[] = {"中重种众终"};
static char PINYIN_mp_zhou[] = {"周粥州轴舟昼"};
static char PINYIN_mp_zhu[] = {"住主猪"};
static char PINYIN_mp_zhua[] = {"抓爪"};
static char PINYIN_mp_zhuai[] = {"拽转"};
static char PINYIN_mp_zhuan[] = {"转专砖"};
static char PINYIN_mp_zhuang[] = {"装撞庄壮"};
static char PINYIN_mp_zhui[] = {"追"};
static char PINYIN_mp_zhun[] = {"准"};
static char PINYIN_mp_zhuo[] = {"捉桌"};
static char PINYIN_mp_zi[] = {"字自子"};
static char PINYIN_mp_zong[] = {"总"};
static char PINYIN_mp_zou[] = {"走"};
static char PINYIN_mp_zu[] = {"组足"};
static char PINYIN_mp_zuan[] = {"钻赚"};
static char PINYIN_mp_zui[] = {"最嘴醉罪"};
static char PINYIN_mp_zun[] = {"尊遵"};
static char PINYIN_mp_zuo[] = {"做作坐"};
#else
/*Chinese Characters UTF-8*/
static char PINYIN_mp_a[] = {"啊阿呵吖嗄腌锕"};
static char PINYIN_mp_ai[] = {"爱矮挨哎碍癌艾唉哀蔼隘埃皑呆嗌嫒瑷暧捱砹嗳锿霭乃剀呃噫奇阂崖"};
static char PINYIN_mp_an[] = {"按安暗岸俺案鞍氨胺厂广庵揞犴铵桉谙鹌埯黯干盒"};
static char PINYIN_mp_ang[] = {"昂肮盎仰"};
static char PINYIN_mp_ao[] = {"袄凹傲奥熬懊敖翱澳嚣拗媪廒骜嗷坳遨聱螯獒鏊鳌鏖岙噢"};
static char PINYIN_mp_ba[] = {"把八吧爸拔罢跋巴芭扒坝霸叭靶笆疤耙捌粑茇岜鲅钯魃菝灞杷伯"};
static char PINYIN_mp_bai[] = {"百白摆败柏拜佰伯稗捭呗薭掰"};
static char PINYIN_mp_ban[] = {"半办班般拌搬版斑板伴扳扮瓣颁绊癍坂钣舨阪瘢"};
static char PINYIN_mp_bang[] = {"帮棒绑磅镑邦榜蚌傍梆膀谤浜蒡彭"};
static char PINYIN_mp_bao[] = {"包抱报饱保暴薄宝爆剥豹刨雹褒堡苞胞鲍炮瀑龅孢煲褓鸨趵曝簿葆勹"};
static char PINYIN_mp_bei[] = {"被北倍杯背悲备碑卑贝辈钡焙狈惫臂褙悖蓓鹎鐾呗邶鞴孛陂碚"};
static char PINYIN_mp_ben[] = {"本奔苯笨夯锛贲畚坌体"};
static char PINYIN_mp_beng[] = {"蹦绷甭崩迸蚌泵甏嘣堋"};
static char PINYIN_mp_bi[] = {"比笔闭鼻碧必避逼毕臂彼鄙壁蓖币弊辟蔽毙庇敝陛毖痹秘泌秕薜荸芘萆匕裨畀俾嬖狴筚箅篦舭荜襞庳铋跸吡愎贲滗濞璧哔髀弼妣婢纰佛拂"};
static char PINYIN_mp_bian[] = {"边变便遍编辩扁贬鞭卞辨辫忭砭匾汴碥蝙褊鳊笾苄窆弁缏煸"};
static char PINYIN_mp_biao[] = {"表标彪膘杓婊飑飙鳔瘭飚镳裱骠镖髟灬"};
static char PINYIN_mp_bie[] = {"别憋鳖瘪蹩"};
static char PINYIN_mp_bin[] = {"宾濒摈彬斌滨膑殡缤髌傧槟玢鬓镔豳份频"};
static char PINYIN_mp_bing[] = {"并病兵冰丙饼屏秉柄炳摒槟禀邴冫枋绠"};
static char PINYIN_mp_bo[] = {"拨波播泊博伯驳玻剥薄勃菠钵搏脖帛般柏舶渤铂箔膊魄卜礴跛檗亳鹁踣啵蕃簸钹饽擘佛擗簿趵"};
static char PINYIN_mp_bu[] = {"不步补布部捕卜簿哺堡埠怖埔瓿逋晡钸钚醭卟"};
static char PINYIN_mp_ca[] = {"擦拆礤嚓"};
static char PINYIN_mp_cai[] = {"猜才材财裁采彩睬踩菜蔡"};
static char PINYIN_mp_can[] = {"蚕残掺参惨惭餐灿骖璨孱黪粲"};
static char PINYIN_mp_cang[] = {"藏仓沧舱苍伧臧"};
static char PINYIN_mp_cao[] = {"草操曹槽糙嘈艚螬漕屮"};
static char PINYIN_mp_ce[] = {"册侧策测厕恻"};
static char PINYIN_mp_cen[] = {"参岑涔"};
static char PINYIN_mp_ceng[] = {"曾层蹭噌"};
static char PINYIN_mp_cha[] = {"查插叉茶差岔搽察茬碴刹诧楂槎镲衩汊馇檫姹杈锸嚓猹苴喳"};
static char PINYIN_mp_chai[] = {"菜柴拆差豺钗瘥虿侪"};
static char PINYIN_mp_chan[] = {"产缠掺搀阐颤铲谗蝉单馋觇婵蒇谄冁廛孱蟾羼镡忏潺禅骣躔澶崭掸"};
static char PINYIN_mp_chang[] = {"长唱常场厂尝肠畅昌敞倡偿猖裳鲳氅菖惝嫦徜鬯阊怅伥昶苌娼倘淌"};
static char PINYIN_mp_chao[] = {"朝抄超吵潮巢炒嘲剿绰钞怊焯耖晁"};
static char PINYIN_mp_che[] = {"车撤扯掣彻尺澈坼砗屮"};
static char PINYIN_mp_chen[] = {"趁称辰臣尘晨沉陈衬橙忱郴榇抻谌碜谶宸龀嗔伧琛沈肜"};
static char PINYIN_mp_cheng[] = {"成乘盛撑称城程承呈秤诚惩逞骋澄橙塍柽埕铖噌铛酲晟裎枨蛏丞瞠净抢"};
static char PINYIN_mp_chi[] = {"吃尺迟池翅痴赤齿耻持斥侈弛驰炽匙踟坻茌墀饬媸豉褫敕哧瘛蚩啻鸱眵螭篪魑叱彳笞嗤傺眙"};
static char PINYIN_mp_chong[] = {"冲重虫充宠崇涌种艟忡舂铳憧茺"};
static char PINYIN_mp_chou[] = {"抽愁臭仇丑稠绸酬筹踌畴瞅惆俦帱瘳雠"};
static char PINYIN_mp_chu[] = {"出处初锄除触橱楚础储畜滁矗搐躇厨雏楮杵刍怵绌亍憷蹰黜蜍樗助褚"};
static char PINYIN_mp_chuai[] = {"揣膪啜嘬搋踹"};
static char PINYIN_mp_chuan[] = {"穿船传串川喘椽氚遄钏舡舛巛"};
static char PINYIN_mp_chuang[] = {"窗床闯创疮幢怆"};
static char PINYIN_mp_chui[] = {"吹垂炊锤捶椎槌棰陲"};
static char PINYIN_mp_chun[] = {"春唇纯蠢醇淳椿蝽莼鹑朐肫"};
static char PINYIN_mp_chuo[] = {"戳绰踔啜龊辍淖辶"};
static char PINYIN_mp_ci[] = {"次此词瓷慈雌磁辞刺茨伺疵赐差兹呲鹚祠糍粢"};
static char PINYIN_mp_cong[] = {"从丛葱匆聪囱琮枞淙璁骢苁"};
static char PINYIN_mp_cou[] = {"凑楱辏腠"};
static char PINYIN_mp_cu[] = {"粗醋簇促卒徂猝蔟蹙酢殂蹴趋趣"};
static char PINYIN_mp_cuan[] = {"窜蹿篡攒汆爨镩撺"};
static char PINYIN_mp_cui[] = {"催脆摧翠崔淬衰瘁粹璀啐悴萃毳榱"};
static char PINYIN_mp_cun[] = {"村寸存蹲忖皴"};
static char PINYIN_mp_cuo[] = {"错撮搓挫措磋嵯厝鹾脞痤蹉瘥锉矬"};
static char PINYIN_mp_da[] = {"大答达打搭瘩塔笪耷哒褡疸怛靼妲沓嗒鞑"};
static char PINYIN_mp_dai[] = {"带代呆戴待袋逮歹贷怠傣大殆呔玳迨岱甙黛骀绐埭隶"};
static char PINYIN_mp_dan[] = {"但单蛋担弹掸胆淡丹耽旦氮诞郸惮石疸澹瘅萏殚眈聃箪赕儋啖膻"};
static char PINYIN_mp_dang[] = {"当党挡档荡谠铛宕菪凼裆砀"};
static char PINYIN_mp_dao[] = {"到道倒刀岛盗稻捣悼导蹈祷帱纛忉焘氘叨刂"};
static char PINYIN_mp_de[] = {"的地得德底锝"};
static char PINYIN_mp_dei[] = {"得"};
static char PINYIN_mp_deng[] = {"等灯邓登澄瞪凳蹬磴镫噔嶝戥簦"};
static char PINYIN_mp_di[] = {"地第底低敌抵滴帝递嫡弟缔堤的涤提笛迪狄翟蒂觌邸谛诋嘀柢骶羝氐棣睇娣荻碲镝坻籴砥"};
static char PINYIN_mp_dia[] = {"嗲"};
static char PINYIN_mp_dian[] = {"点电店殿淀掂颠垫碘惦奠典佃靛滇甸踮钿坫阽癫簟玷巅癜"};
static char PINYIN_mp_diao[] = {"掉钓叼吊雕调刁碉凋鸟铞铫鲷貂"};
static char PINYIN_mp_die[] = {"爹跌叠碟蝶迭谍牒堞瓞揲蹀耋鲽垤喋佚"};
static char PINYIN_mp_ding[] = {"顶定盯订叮丁钉鼎锭町玎铤腚碇疔仃耵酊啶"};
static char PINYIN_mp_diu[] = {"丢铥"};
static char PINYIN_mp_dong[] = {"动东懂洞冻冬董栋侗恫峒鸫垌胨胴硐氡岽咚"};
static char PINYIN_mp_dou[] = {"都斗豆逗陡抖痘兜读蚪窦篼蔸渎钭"};
static char PINYIN_mp_du[] = {"读度毒渡堵独肚镀赌睹杜督都犊妒顿蠹笃嘟渎椟牍黩髑芏竺"};
static char PINYIN_mp_duan[] = {"段短断端锻缎椴煅簖"};
static char PINYIN_mp_dui[] = {"对队堆兑敦镦碓怼憝"};
static char PINYIN_mp_dun[] = {"吨顿蹲墩敦钝盾囤遁不趸沌盹镦礅炖砘"};
static char PINYIN_mp_duo[] = {"多朵夺舵剁垛跺惰堕掇哆驮度躲踱沲咄铎裰哚缍隋"};
static char PINYIN_mp_e[] = {"饿哦额鹅蛾扼俄讹阿遏峨娥恶厄鄂锇谔垩锷阏萼苊轭婀莪鳄颚腭愕呃噩鹗屙"};
static char PINYIN_mp_ei[] = {"诶"};
static char PINYIN_mp_en[] = {"恩嗯摁蒽"};
static char PINYIN_mp_er[] = {"而二耳儿饵尔贰洱珥鲕鸸佴迩铒"};
static char PINYIN_mp_fa[] = {"发法罚伐乏筏阀珐垡砝"};
static char PINYIN_mp_fan[] = {"反饭翻番犯凡帆返泛繁烦贩范樊藩矾钒燔蘩畈蕃蹯梵幡拚袢"};
static char PINYIN_mp_fang[] = {"放房防纺芳方访仿坊妨肪钫彷邡枋舫鲂匚"};
static char PINYIN_mp_fei[] = {"非飞肥费肺废匪吠沸菲诽啡篚蜚腓扉妃斐狒芾悱镄霏翡榧淝鲱绯痱怫砩"};
static char PINYIN_mp_fen[] = {"分份芬粉坟奋愤纷忿粪酚焚吩氛汾棼瀵鲼玢偾鼢"};
static char PINYIN_mp_feng[] = {"风封逢缝蜂丰枫疯冯奉讽凤峰锋烽砜俸酆葑沣唪"};
static char PINYIN_mp_fo[] = {"佛"};
static char PINYIN_mp_fou[] = {"否缶不"};
static char PINYIN_mp_fu[] = {"副幅扶浮富福负伏付复服附俯芙斧赴缚拂夫父符孵敷赋辅府腐腹妇抚覆辐肤氟佛俘傅讣弗涪袱市甫釜脯腑阜咐黼砩苻趺跗蚨芾鲋幞宓茯滏蜉拊呒菔蝠鳆蝮绂绋赙罘稃匐麸凫桴莩孚馥驸怫祓呋郛艴黻阝"};
static char PINYIN_mp_ga[] = {"噶胳夹嘎咖轧钆伽旮尬尕尜呷"};
static char PINYIN_mp_gai[] = {"该改盖概钙芥溉戤垓丐陔赅"};
static char PINYIN_mp_gan[] = {"赶干感敢竿甘肝柑杆赣秆旰酐矸疳泔苷擀绀橄澉淦尴坩乾"};
static char PINYIN_mp_gang[] = {"刚钢纲港缸岗杠冈肛扛筻罡戆"};
static char PINYIN_mp_gao[] = {"高搞告稿膏篙羔糕镐皋郜诰杲缟睾槔锆槁藁"};
static char PINYIN_mp_ge[] = {"个各歌割哥搁格阁隔革咯胳葛蛤戈鸽疙盖屹合铬硌骼颌袼塥虼圪镉仡舸鬲嗝膈搿纥哿"};
static char PINYIN_mp_gei[] = {"给"};
static char PINYIN_mp_gen[] = {"跟根哏茛亘艮"};
static char PINYIN_mp_geng[] = {"更耕颈梗耿庚羹埂赓鲠哽绠"};
static char PINYIN_mp_gong[] = {"工公功共弓攻宫供恭拱贡躬巩汞龚红肱觥珙蚣"};
static char PINYIN_mp_gou[] = {"够沟狗钩勾购构苟垢句岣彀枸鞲觏缑笱诟遘媾篝佝"};
static char PINYIN_mp_gu[] = {"古股鼓谷故孤箍姑顾固雇估咕骨辜沽蛊贾菇梏鸪汩轱崮菰鹄鹘钴臌酤呱鲴诂牯瞽毂锢牿痼觚蛄罟嘏"};
static char PINYIN_mp_gua[] = {"挂刮瓜寡剐褂卦呱胍鸹栝诖括"};
static char PINYIN_mp_guai[] = {"怪拐乖掴"};
static char PINYIN_mp_guan[] = {"关管官观馆惯罐灌冠贯棺纶盥矜莞掼涫鳏鹳倌"};
static char PINYIN_mp_guang[] = {"光广逛桄犷咣胱潢"};
static char PINYIN_mp_gui[] = {"归贵鬼跪轨规硅桂柜龟诡闺瑰圭刽傀癸炔庋宄桧刿鳜鲑皈匦妫晷簋炅匮"};
static char PINYIN_mp_gun[] = {"滚棍辊鲧衮磙绲丨"};
static char PINYIN_mp_guo[] = {"过国果裹锅郭涡埚椁聒馘猓崞掴帼呙虢蜾蝈"};
static char PINYIN_mp_ha[] = {"哈蛤虾铪呵"};
static char PINYIN_mp_hai[] = {"还海害咳氦孩骇骸亥嗨醢胲"};
static char PINYIN_mp_han[] = {"喊含汗寒汉旱酣韩焊涵函憨翰罕撼捍憾悍邯邗菡撖瀚阚顸蚶焓颔晗鼾厂旰"};
static char PINYIN_mp_hang[] = {"行巷航夯杭吭颃沆绗珩桁炕肮"};
static char PINYIN_mp_hao[] = {"好号浩嚎壕郝毫豪耗貉镐昊颢灏嚆蚝嗥皓蒿濠薅"};
static char PINYIN_mp_he[] = {"和喝合河禾核何呵荷贺赫褐盒鹤菏貉阂涸吓嗬劾盍翮阖颌壑诃纥曷鹄"};
static char PINYIN_mp_hei[] = {"黑嘿嗨"};
static char PINYIN_mp_hen[] = {"很狠恨痕哏"};
static char PINYIN_mp_heng[] = {"横恒哼衡亨行桁珩蘅"};
static char PINYIN_mp_hong[] = {"红轰哄虹洪宏烘鸿弘讧訇蕻闳薨黉荭泓"};
static char PINYIN_mp_hou[] = {"后厚吼喉侯候猴鲎篌堠後逅糇骺瘊"};
static char PINYIN_mp_hu[] = {"湖户呼虎壶互胡护糊弧忽狐蝴葫沪乎戏核和瑚唬鹕冱怙鹱笏戽扈鹘浒祜醐琥囫烀轷瓠煳斛鹄猢惚岵滹觳唿槲"};
static char PINYIN_mp_hua[] = {"话花化画华划滑哗猾豁铧桦骅砉"};
static char PINYIN_mp_huai[] = {"坏怀淮槐徊划踝"};
static char PINYIN_mp_huan[] = {"换还唤环患缓欢幻宦涣焕豢桓痪漶獾擐逭鲩郇鬟寰奂锾圜洹萑缳浣垸"};
static char PINYIN_mp_huang[] = {"黄慌晃荒簧凰皇谎惶蝗磺恍煌幌隍肓潢篁徨鳇遑癀湟蟥璜"};
static char PINYIN_mp_hui[] = {"回会灰绘挥汇辉毁悔惠晦徽恢秽慧贿蛔讳徊卉烩诲彗浍珲蕙喙恚哕晖隳麾诙蟪茴洄咴虺荟缋堕桧"};
static char PINYIN_mp_hun[] = {"混昏荤浑婚魂阍珲馄溷诨"};
static char PINYIN_mp_huo[] = {"或活火伙货和获祸豁霍惑嚯镬耠劐藿攉锪蠖钬夥"};
static char PINYIN_mp_ji[] = {"几及急既即机鸡积记级极计挤己季寄纪系基激吉脊际击圾畸箕肌饥迹讥姬绩棘辑籍缉集疾汲嫉蓟技冀伎祭剂悸济寂期其奇忌齐妓继给革稽墼洎鲚屐齑戟鲫嵇矶稷戢虮诘笈暨笄剞叽蒺跻嵴掎跽霁唧畿荠瘠玑羁丌偈芨佶赍楫髻咭蕺觊麂"};
static char PINYIN_mp_jia[] = {"家加假价架甲佳夹嘉驾嫁枷荚颊钾稼茄贾铗葭迦戛浃镓痂恝岬跏嘏伽胛笳珈瘕郏袈蛱拮挟袷颉"};
static char PINYIN_mp_jian[] = {"见件减尖间键贱肩兼建检箭煎简剪歼监坚奸健艰荐剑渐溅涧鉴浅践捡柬笺俭碱硷拣舰槛缄茧饯翦鞯戋谏牮枧腱趼缣搛戬毽菅鲣笕谫楗囝蹇裥踺睑謇鹣蒹僭锏湔堑犍"};
static char PINYIN_mp_jiang[] = {"将讲江奖降浆僵姜酱蒋疆匠强桨虹豇礓缰犟耩绛茳糨洚"};
static char PINYIN_mp_jiao[] = {"叫脚交角教较缴觉焦胶娇绞校搅骄狡浇矫郊嚼蕉轿窖椒礁饺铰酵侥剿徼艽僬蛟敫峤跤姣皎茭鹪噍醮佼湫鲛挢"};
static char PINYIN_mp_jie[] = {"接节街借皆截解界结届姐揭戒介阶劫芥竭洁疥藉价楷秸桔杰捷诫睫家偈桀喈拮骱羯蚧嗟颉鲒婕碣讦孑疖诘卩"};
static char PINYIN_mp_jin[] = {"进近今仅紧金斤尽劲禁浸锦晋筋津谨巾襟烬靳廑瑾馑槿衿堇荩矜噤缙卺妗赆觐"};
static char PINYIN_mp_jing[] = {"竟静井惊经镜京净敬精景警竞境径荆晶鲸粳颈兢茎睛劲痉靖肼獍阱腈弪刭憬婧胫菁儆旌迳靓泾箐"};
static char PINYIN_mp_jiong[] = {"窘炯扃迥炅冂"};
static char PINYIN_mp_jiu[] = {"就九酒旧久揪救纠舅究韭厩臼玖灸咎疚赳鹫蹴僦柩桕鬏鸠阄啾"};
static char PINYIN_mp_ju[] = {"句举巨局具距锯剧居聚拘菊矩沮拒惧鞠狙驹且据柜桔俱车咀疽踞炬倨醵裾屦犋苴窭飓锔椐苣琚掬榘龃趄莒雎遽橘踽榉鞫钜讵枸渠瞿"};
static char PINYIN_mp_juan[] = {"卷圈倦鹃捐娟眷绢鄄锩蠲镌狷桊涓隽"};
static char PINYIN_mp_jue[] = {"决绝觉角爵掘诀撅倔抉攫嚼脚桷噱橛嗟觖劂爝矍镢獗珏崛蕨噘谲蹶孓厥"};
static char PINYIN_mp_jun[] = {"军君均菌俊峻龟竣骏钧浚郡筠麇皲捃匀"};
static char PINYIN_mp_ka[] = {"卡喀咯咖胩咔佧"};
static char PINYIN_mp_kai[] = {"开揩凯慨楷垲剀锎铠锴忾恺蒈劾"};
static char PINYIN_mp_kan[] = {"看砍堪刊嵌坎槛勘龛戡侃瞰莰阚凵"};
static char PINYIN_mp_kang[] = {"抗炕扛糠康慷亢钪闶伉"};
static char PINYIN_mp_kao[] = {"靠考烤拷栲犒尻铐"};
static char PINYIN_mp_ke[] = {"咳可克棵科颗刻课客壳渴苛柯磕坷呵恪岢蝌缂蚵轲窠钶氪颏瞌锞稞珂髁疴嗑溘骒铪"};
static char PINYIN_mp_ken[] = {"肯啃恳垦裉龈"};
static char PINYIN_mp_keng[] = {"坑吭铿"};
static char PINYIN_mp_kong[] = {"空孔控恐倥崆箜"};
static char PINYIN_mp_kou[] = {"口扣抠寇蔻芤眍筘叩佝"};
static char PINYIN_mp_ku[] = {"哭库苦枯裤窟酷刳骷喾堀绔"};
static char PINYIN_mp_kua[] = {"跨垮挎夸胯侉"};
static char PINYIN_mp_kuai[] = {"快块筷会侩哙蒯浍郐狯脍"};
static char PINYIN_mp_kuan[] = {"宽款髋"};
static char PINYIN_mp_kuang[] = {"矿筐狂框况旷匡眶诳邝纩夼诓圹贶哐磺湟"};
static char PINYIN_mp_kui[] = {"亏愧奎窥溃葵魁馈盔傀岿匮愦揆睽跬聩篑喹逵暌蒉悝喟馗蝰隗夔"};
static char PINYIN_mp_kun[] = {"捆困昆坤鲲锟髡琨醌阃悃"};
static char PINYIN_mp_kuo[] = {"阔扩括廓适蛞栝"};
static char PINYIN_mp_la[] = {"拉啦辣蜡腊喇垃蓝落瘌邋砬剌旯"};
static char PINYIN_mp_lai[] = {"来赖莱濑赉崃涞铼籁徕睐癞"};
static char PINYIN_mp_lan[] = {"蓝兰烂拦篮懒栏揽缆滥阑谰婪澜览榄岚褴镧斓罱漤啉"};
static char PINYIN_mp_lang[] = {"浪狼廊郎朗榔琅稂螂莨啷锒阆蒗"};
static char PINYIN_mp_lao[] = {"老捞牢劳烙涝落姥酪络佬潦耢铹醪铑唠栳崂痨"};
static char PINYIN_mp_le[] = {"了乐勒肋鳓仂叻泐嘞"};
static char PINYIN_mp_lei[] = {"类累泪雷垒勒擂蕾肋镭儡磊缧诔耒酹羸嫘檑嘞漯"};
static char PINYIN_mp_leng[] = {"冷棱楞愣塄"};
static char PINYIN_mp_li[] = {"里离力立李例哩理利梨厘礼历丽吏砾漓莉傈荔俐痢狸粒沥隶栗璃鲤厉励犁黎篱郦鹂笠坜苈鳢缡跞蜊锂悝澧粝蓠枥蠡鬲呖砺嫠篥疠疬猁藜溧鲡戾栎唳醴轹詈骊罹逦俪喱雳黧莅俚蛎娌"};
static char PINYIN_mp_lia[] = {"俩"};
static char PINYIN_mp_lian[] = {"连联练莲恋脸炼链敛怜廉帘镰涟蠊琏殓蔹鲢奁潋臁裢濂裣楝"};
static char PINYIN_mp_liang[] = {"两亮辆凉粮梁量良晾谅俩粱墚靓踉椋魉莨"};
static char PINYIN_mp_liao[] = {"了料撩聊撂疗廖燎辽僚寥镣潦钌蓼尥寮缭獠鹩嘹"};
static char PINYIN_mp_lie[] = {"列裂猎劣烈咧埒捩鬣趔躐冽洌"};
static char PINYIN_mp_lin[] = {"林临淋邻磷鳞赁吝拎琳霖凛遴嶙蔺粼麟躏辚廪懔瞵檩膦啉"};
static char PINYIN_mp_ling[] = {"另令领零铃玲灵岭龄凌陵菱伶羚棱翎蛉苓绫瓴酃呤泠棂柃鲮聆囹"};
static char PINYIN_mp_liu[] = {"六流留刘柳溜硫瘤榴琉馏碌陆绺锍鎏镏浏骝旒鹨熘遛"};
static char PINYIN_mp_lo[] = {"咯"};
static char PINYIN_mp_long[] = {"龙拢笼聋隆垄弄咙窿陇垅胧珑茏泷栊癃砻"};
static char PINYIN_mp_lou[] = {"楼搂漏陋露娄篓偻蝼镂蒌耧髅喽瘘嵝"};
static char PINYIN_mp_lu[] = {"路露录鹿陆炉卢鲁卤芦颅庐碌掳绿虏赂戮潞禄麓六鲈栌渌蓼逯泸轳氇簏橹辂垆胪噜镥辘漉撸璐鸬鹭舻"};
static char PINYIN_mp_luan[] = {"乱卵滦峦孪挛栾銮脔娈鸾"};
static char PINYIN_mp_lun[] = {"论轮抡伦沦仑纶囵"};
static char PINYIN_mp_luo[] = {"落罗锣裸骡烙箩螺萝洛骆逻络咯荦漯蠃雒倮硌椤捋脶瘰摞泺珞镙猡跞"};
static char PINYIN_mp_lv[] = {"绿率铝驴旅屡滤吕律氯缕侣虑履偻膂榈闾捋褛稆"};
static char PINYIN_mp_lue[] = {"略掠锊"};
static char PINYIN_mp_ma[] = {"吗妈马嘛麻骂抹码玛蚂摩唛蟆犸嬷杩"};
static char PINYIN_mp_mai[] = {"买卖迈埋麦脉劢霾荬"};
static char PINYIN_mp_man[] = {"满慢瞒漫蛮蔓曼馒埋谩幔鳗墁螨镘颟鞔缦熳"};
static char PINYIN_mp_mang[] = {"忙芒盲莽茫氓硭邙蟒漭"};
static char PINYIN_mp_mao[] = {"毛冒帽猫矛卯貌茂贸铆锚茅耄茆瑁蝥髦懋昴牦瞀峁袤蟊旄泖"};
static char PINYIN_mp_me[] = {"么麽"};
static char PINYIN_mp_mei[] = {"没每煤镁美酶妹枚霉玫眉梅寐昧媒糜媚谜沫嵋猸袂湄浼鹛莓魅镅楣"};
static char PINYIN_mp_men[] = {"门们闷懑扪钔焖汶鞔"};
static char PINYIN_mp_meng[] = {"猛梦蒙锰孟盟檬萌氓礞蜢勐懵甍蠓虻朦艋艨瞢"};
static char PINYIN_mp_mi[] = {"米密迷眯蜜谜觅秘弥幂靡糜泌醚蘼縻咪汨麋祢猕弭谧芈脒宓敉嘧糸"};
static char PINYIN_mp_mian[] = {"面棉免绵眠缅勉冕娩腼湎眄沔黾渑宀"};
static char PINYIN_mp_miao[] = {"秒苗庙妙描瞄藐渺眇缪缈邈淼喵杪鹋"};
static char PINYIN_mp_mie[] = {"灭蔑咩篾蠛乜"};
static char PINYIN_mp_min[] = {"民抿敏闽皿悯珉愍缗闵玟苠泯黾鳘岷"};
static char PINYIN_mp_ming[] = {"名明命鸣铭螟盟冥瞑暝茗溟酩"};
static char PINYIN_mp_miu[] = {"谬缪"};
static char PINYIN_mp_mo[] = {"摸磨抹末膜墨没莫默魔模摩摹漠陌蘑脉沫万无冒寞秣瘼殁镆嫫谟蓦貊貘麽茉馍耱么嘿嬷"};
static char PINYIN_mp_mou[] = {"某谋牟眸蛑鍪侔缪哞厶"};
static char PINYIN_mp_mu[] = {"木母亩幕目墓牧牟模穆暮牡拇募慕睦姆姥钼毪坶沐仫苜"};
static char PINYIN_mp_na[] = {"那拿哪纳钠娜呐南衲捺镎肭内"};
static char PINYIN_mp_nai[] = {"乃耐奶奈氖哪萘艿柰鼐佴能"};
static char PINYIN_mp_nan[] = {"难南男赧囡蝻楠喃腩囝"};
static char PINYIN_mp_nang[] = {"囊馕曩囔攮"};
static char PINYIN_mp_nao[] = {"闹脑恼挠淖孬铙瑙垴呶蛲猱硇"};
static char PINYIN_mp_ne[] = {"呢哪那呐讷疒"};
static char PINYIN_mp_nei[] = {"内哪馁那"};
static char PINYIN_mp_nen[] = {"嫩恁"};
static char PINYIN_mp_neng[] = {"能"};
static char PINYIN_mp_ng[] = {"嗯"};
static char PINYIN_mp_ni[] = {"你泥拟腻逆呢溺倪尼匿妮霓铌昵坭祢猊伲怩鲵睨旎"};
static char PINYIN_mp_nian[] = {"年念捻撵拈碾蔫粘廿黏辇鲇鲶埝辗"};
static char PINYIN_mp_niang[] = {"娘酿"};
static char PINYIN_mp_niao[] = {"鸟尿袅茑脲嬲溺"};
static char PINYIN_mp_nie[] = {"捏镍聂孽涅镊啮陧蘖嗫臬蹑颞乜"};
static char PINYIN_mp_nin[] = {"您恁"};
static char PINYIN_mp_ning[] = {"拧凝宁柠狞泞佞甯咛聍"};
static char PINYIN_mp_niu[] = {"牛扭纽钮狃忸妞拗"};
static char PINYIN_mp_nong[] = {"弄浓农脓哝侬"};
static char PINYIN_mp_nou[] = {"耨"};
static char PINYIN_mp_nu[] = {"怒努奴孥胬驽弩呶帑"};
static char PINYIN_mp_nv[] = {"女钕恧衄"};
static char PINYIN_mp_nue[] = {"虐疟谑"};
static char PINYIN_mp_nuan[] = {"暖"};
static char PINYIN_mp_nuo[] = {"挪诺懦糯娜喏傩锘搦"};
static char PINYIN_mp_o[] = {"哦喔噢"};
static char PINYIN_mp_ou[] = {"偶呕欧藕鸥区沤殴怄瓯讴耦"};
static char PINYIN_mp_pa[] = {"怕爬趴啪耙扒帕琶派筢杷葩钯"};
static char PINYIN_mp_pai[] = {"派排拍牌迫徘湃哌俳蒎"};
static char PINYIN_mp_pan[] = {"盘盼判攀畔潘叛磐番般胖襻蟠袢泮拚爿蹒"};
static char PINYIN_mp_pang[] = {"旁胖耪庞乓膀磅滂彷逄螃仿"};
static char PINYIN_mp_pao[] = {"跑抛炮泡刨袍咆狍匏庖疱脬"};
static char PINYIN_mp_pei[] = {"陪配赔呸胚佩培沛裴旆锫帔醅霈辔淠"};
static char PINYIN_mp_pen[] = {"喷盆湓"};
static char PINYIN_mp_peng[] = {"碰捧棚砰蓬朋彭鹏烹硼膨抨澎篷怦堋蟛嘭"};
static char PINYIN_mp_pi[] = {"批皮披匹劈辟坯屁脾僻疲痞霹琵毗啤譬砒否貔丕圮媲癖仳擗郫甓枇睥蜱鼙邳吡陂铍庀罴埤纰陴淠噼蚍裨芘"};
static char PINYIN_mp_pian[] = {"片篇骗偏便扁翩缏犏骈胼蹁谝"};
static char PINYIN_mp_piao[] = {"票飘漂瓢朴螵莩嫖瞟殍缥嘌骠剽"};
static char PINYIN_mp_pie[] = {"瞥撇苤氕"};
static char PINYIN_mp_pin[] = {"品贫聘拼频嫔榀姘牝颦"};
static char PINYIN_mp_ping[] = {"平凭瓶评屏乒萍苹坪冯娉鲆枰俜"};
static char PINYIN_mp_po[] = {"破坡颇婆泼迫泊魄朴繁粕笸皤钋陂鄱攴叵珀钷泺"};
static char PINYIN_mp_pou[] = {"剖掊裒"};
static char PINYIN_mp_pu[] = {"扑铺谱脯仆蒲葡朴菩莆瀑曝埔圃浦堡普暴镨噗匍溥濮氆蹼璞镤攴攵"};
static char PINYIN_mp_qi[] = {"起其七气期齐器妻骑汽棋奇欺漆启戚柒岂砌弃泣祁凄企乞契歧祈栖畦脐崎稽迄缉沏讫旗祺颀骐屺岐蹊萁蕲桤憩芪荠萋芑汔亟鳍俟槭嘁蛴綦亓欹琪麒琦蜞圻杞葺碛淇祗耆绮丌伎綮"};
static char PINYIN_mp_qia[] = {"恰卡掐洽袷葜髂"};
static char PINYIN_mp_qian[] = {"前钱千牵浅签欠铅嵌钎迁钳乾谴谦潜歉纤扦遣黔堑仟岍钤褰箝掮搴倩慊悭愆虔芡荨缱佥芊阡肷茜椠犍骞凵"};
static char PINYIN_mp_qiang[] = {"强枪墙抢腔呛羌蔷将蜣跄戗襁戕炝镪锖锵羟樯嫱"};
static char PINYIN_mp_qiao[] = {"桥瞧敲巧翘锹壳鞘撬悄俏窍雀乔侨峭橇樵荞跷硗憔谯鞒愀缲诮劁峤"};
static char PINYIN_mp_qie[] = {"切且怯窃茄砌郄趄惬锲妾箧慊伽挈"};
static char PINYIN_mp_qin[] = {"亲琴侵勤擒寝秦芹沁禽钦吣覃矜衾芩溱廑嗪螓噙揿檎锓"};
static char PINYIN_mp_qing[] = {"请轻清青情晴氢倾庆擎顷亲卿氰圊謦檠箐苘蜻黥罄鲭磬綮倩"};
static char PINYIN_mp_qiong[] = {"穷琼跫穹邛蛩茕銎筇"};
static char PINYIN_mp_qiu[] = {"求球秋丘泅仇邱囚酋龟楸蚯裘糗蝤巯逑俅虬赇鳅犰湫鼽遒艽"};
static char PINYIN_mp_qu[] = {"去取区娶渠曲趋趣屈驱蛆躯龋戌蠼蘧祛蕖磲劬诎鸲阒麴癯衢黢璩氍觑蛐朐瞿岖苣"};
static char PINYIN_mp_quan[] = {"全权劝圈拳犬泉券颧痊醛铨筌绻诠辁畎鬈悛蜷荃犭"};
static char PINYIN_mp_que[] = {"却缺确雀瘸鹊炔榷阙阕悫芍"};
static char PINYIN_mp_qui[] = {"鼽"};
static char PINYIN_mp_qun[] = {"群裙逡麇"};
static char PINYIN_mp_ran[] = {"染燃然冉髯苒蚺"};
static char PINYIN_mp_rang[] = {"让嚷瓤攘壤穰禳"};
static char PINYIN_mp_rao[] = {"饶绕扰荛桡娆"};
static char PINYIN_mp_re[] = {"热若惹喏"};
static char PINYIN_mp_ren[] = {"人任忍认刃仁韧妊纫壬饪轫仞荏葚衽稔亻"};
static char PINYIN_mp_reng[] = {"仍扔艿"};
static char PINYIN_mp_ri[] = {"日"};
static char PINYIN_mp_rong[] = {"容绒融溶熔荣戎蓉冗茸榕狨嵘肜蝾"};
static char PINYIN_mp_rou[] = {"肉揉柔糅蹂鞣"};
static char PINYIN_mp_ru[] = {"如入汝儒茹乳褥辱蠕孺蓐襦铷嚅缛濡薷颥溽洳"};
static char PINYIN_mp_ruan[] = {"软阮朊"};
static char PINYIN_mp_rui[] = {"瑞蕊锐睿芮蚋枘蕤"};
static char PINYIN_mp_run[] = {"闰润"};
static char PINYIN_mp_ruo[] = {"若弱偌箬"};
static char PINYIN_mp_sa[] = {"撒洒萨挲仨卅飒脎"};
static char PINYIN_mp_sai[] = {"塞腮鳃思赛噻"};
static char PINYIN_mp_san[] = {"三散伞叁馓糁毵霰参"};
static char PINYIN_mp_sang[] = {"桑丧嗓颡磉搡"};
static char PINYIN_mp_sao[] = {"扫嫂搔骚梢埽鳋臊缫瘙缲"};
static char PINYIN_mp_se[] = {"色涩瑟塞啬铯穑槭"};
static char PINYIN_mp_sen[] = {"森"};
static char PINYIN_mp_seng[] = {"僧"};
static char PINYIN_mp_sha[] = {"杀沙啥纱傻砂刹莎厦煞杉嗄唼鲨霎铩痧裟挲歃噎"};
static char PINYIN_mp_shai[] = {"晒筛色酾"};
static char PINYIN_mp_shan[] = {"山闪衫善扇杉删煽单珊掺赡栅苫掸膳陕汕擅缮嬗蟮芟禅跚鄯潸鳝姗剡骟疝膻讪钐舢埏彡"};
static char PINYIN_mp_shang[] = {"上伤尚商赏晌墒汤裳熵觞绱殇垧"};
static char PINYIN_mp_shao[] = {"少烧捎哨勺梢稍邵韶绍芍召鞘苕劭潲艄蛸筲杓"};
static char PINYIN_mp_she[] = {"社射蛇设舌摄舍折涉赊赦慑奢歙厍畲猞麝滠佘拾揲"};
static char PINYIN_mp_shei[] = {"谁"};
static char PINYIN_mp_shen[] = {"身伸深婶神甚渗肾审申沈绅呻参砷什娠慎葚糁莘诜谂矧椹渖蜃哂胂吲"};
static char PINYIN_mp_sheng[] = {"声省剩生升绳胜盛圣甥牲乘晟渑眚笙嵊"};
static char PINYIN_mp_shi[] = {"是使十时事室市石师试史式识虱矢拾屎驶始似嘘示士世柿匙拭誓逝势什殖峙嗜噬失适仕侍释饰氏狮食恃蚀视实施湿诗尸豕莳埘铈舐鲥鲺贳轼蓍筮炻谥弑酾螫礻耆饣"};
static char PINYIN_mp_shou[] = {"手受收首守瘦授兽售熟寿艏狩绶扌"};
static char PINYIN_mp_shu[] = {"书树数熟输梳叔属束术述蜀黍鼠淑赎孰蔬疏戍竖墅庶薯漱恕枢暑殊抒曙署舒姝摅秫纾沭毹腧塾菽殳澍倏疋荼"};
static char PINYIN_mp_shua[] = {"刷耍唰"};
static char PINYIN_mp_shuai[] = {"摔甩率帅衰蟀"};
static char PINYIN_mp_shuan[] = {"栓拴闩涮"};
static char PINYIN_mp_shuang[] = {"双霜爽泷孀"};
static char PINYIN_mp_shui[] = {"水谁睡税说氵"};
static char PINYIN_mp_shun[] = {"顺吮瞬舜"};
static char PINYIN_mp_shuo[] = {"说数硕烁朔搠妁槊蒴铄"};
static char PINYIN_mp_si[] = {"四司丝撕似私嘶思寺斯食伺死厕肆饲嗣巳耜驷兕蛳厮汜锶泗笥咝鸶姒厶缌祀澌俟糸纟"};
static char PINYIN_mp_song[] = {"送松耸宋颂诵怂讼竦菘淞悚嵩凇崧忪"};
static char PINYIN_mp_sou[] = {"艘搜擞嗽嗾嗖飕叟薮锼馊瞍溲螋"};
static char PINYIN_mp_su[] = {"素速诉塑宿俗苏肃粟酥缩溯僳愫簌觫稣夙嗉谡蔌涑"};
static char PINYIN_mp_suan[] = {"酸算蒜狻"};
static char PINYIN_mp_sui[] = {"岁随碎虽穗遂尿隋髓绥隧祟眭谇濉邃燧荽睢粹"};
static char PINYIN_mp_sun[] = {"孙损笋榫荪飧狲隼"};
static char PINYIN_mp_suo[] = {"所缩锁琐索梭蓑莎唆挲睃嗍唢桫嗦娑羧"};
static char PINYIN_mp_ta[] = {"他她它踏塔塌拓獭挞蹋溻趿鳎沓榻漯遢铊闼嗒"};
static char PINYIN_mp_tai[] = {"太抬台态胎苔泰酞汰炱肽跆呔鲐钛薹邰骀"};
static char PINYIN_mp_tan[] = {"谈叹探滩弹碳摊潭贪坛痰毯坦炭瘫谭坍檀袒钽郯镡锬覃澹昙忐"};
static char PINYIN_mp_tang[] = {"躺趟堂糖汤塘烫倘淌唐搪棠膛螳樘羰醣瑭镗傥饧溏耥帑铴螗"};
static char PINYIN_mp_tao[] = {"套掏逃桃讨淘涛滔陶绦萄鼗啕洮韬饕叨焘"};
static char PINYIN_mp_te[] = {"特忑慝铽忒"};
static char PINYIN_mp_teng[] = {"疼腾藤誊滕"};
static char PINYIN_mp_ti[] = {"提替体题踢蹄剃剔梯锑啼涕嚏惕屉醍鹈绨缇倜裼逖荑悌棣"};
static char PINYIN_mp_tian[] = {"天田添填甜舔恬腆佃掭钿阗忝殄畋栝"};
static char PINYIN_mp_tiao[] = {"条跳挑调迢眺龆笤祧蜩髫佻窕鲦苕粜啁"};
static char PINYIN_mp_tie[] = {"铁贴帖萜餮"};
static char PINYIN_mp_ting[] = {"听停挺厅亭艇庭廷烃汀町莛铤葶婷蜓梃霆"};
static char PINYIN_mp_tong[] = {"同通痛铜桶筒捅统童彤桐瞳恫侗酮潼茼仝砼峒恸佟嗵垌僮"};
static char PINYIN_mp_tou[] = {"头偷透投钭骰亠愉"};
static char PINYIN_mp_tu[] = {"土图兔涂吐秃突徒凸途屠酴荼钍菟堍"};
static char PINYIN_mp_tuan[] = {"团湍疃抟彖"};
static char PINYIN_mp_tui[] = {"腿推退褪颓蜕煺忒弟"};
static char PINYIN_mp_tun[] = {"吞屯褪臀囤氽饨豚暾"};
static char PINYIN_mp_tuo[] = {"拖脱托妥驮拓驼椭唾鸵陀魄橐柝跎乇坨佗庹酡柁鼍沱箨砣铊隋舵"};
static char PINYIN_mp_wa[] = {"挖瓦蛙哇娃洼凹袜佤娲腽"};
static char PINYIN_mp_wai[] = {"外歪崴呙"};
static char PINYIN_mp_wan[] = {"完万晚碗玩弯挽湾丸腕宛婉烷顽豌惋娩皖蔓莞脘蜿绾芄琬纨剜畹菀箢"};
static char PINYIN_mp_wang[] = {"望忘王往网亡枉旺汪妄芒辋魍惘罔尢"};
static char PINYIN_mp_wei[] = {"为位未围喂胃微味尾伪威伟卫危违委魏唯维畏惟韦巍蔚谓尉潍纬慰桅萎苇渭遗葳帏艉鲔娓逶闱隈沩玮涠帷崴隗诿洧偎猥猬嵬軎韪炜煨圩薇痿倭隹"};
static char PINYIN_mp_wen[] = {"问文闻稳温吻蚊纹瘟紊汶阌刎雯璺韫"};
static char PINYIN_mp_weng[] = {"翁嗡瓮蕹蓊"};
static char PINYIN_mp_wo[] = {"我握窝卧挝沃蜗涡斡倭幄龌肟莴喔渥硪媪"};
static char PINYIN_mp_wu[] = {"无五屋物舞雾误捂污悟勿钨武戊务呜伍吴午吾侮乌毋恶诬芜巫晤梧坞妩蜈牾寤兀怃阢邬忤骛於鋈仵杌鹜婺迕痦芴焐庑鹉鼯浯圬亡唔"};
static char PINYIN_mp_xi[] = {"西洗细吸戏系喜席稀溪熄锡膝息袭惜习嘻夕悉矽熙希檄牺晰昔媳硒铣烯腊析隙栖汐犀蜥奚浠葸饩屣玺嬉禊兮翕穸禧僖淅蓰舾蹊醯欷皙蟋羲茜徙隰唏曦螅歙樨阋粞熹觋菥鼷裼舄郄褶鳃郗"};
static char PINYIN_mp_xia[] = {"下吓夏峡虾瞎霞狭匣侠辖厦暇唬狎柙呷黠硖罅遐瑕假"};
static char PINYIN_mp_xian[] = {"先线县现显掀闲献嫌陷险鲜弦衔馅限咸锨仙腺贤纤宪舷涎羡铣见苋藓岘痫莶籼娴蚬猃祆冼燹跣跹酰暹氙鹇筅霰彡"};
static char PINYIN_mp_xiang[] = {"想向象项响香乡相像箱巷享镶厢降翔祥橡详湘襄飨鲞骧蟓庠芗饷缃葙"};
static char PINYIN_mp_xiao[] = {"小笑消削销萧效宵晓肖孝硝淆啸霄哮嚣校魈蛸骁枵哓崤筱潇逍枭绡箫俏姣"};
static char PINYIN_mp_xie[] = {"写些鞋歇斜血谢卸挟屑蟹泻懈泄楔邪协械谐蝎携胁解契叶绁颉缬獬榭廨撷偕瀣渫亵榍邂薤躞燮勰鲑"};
static char PINYIN_mp_xin[] = {"新心欣信芯薪锌辛寻衅忻歆囟莘镡馨鑫昕忄"};
static char PINYIN_mp_xing[] = {"性行型形星醒姓腥刑杏兴幸邢猩惺省硎悻荥陉擤荇饧"};
static char PINYIN_mp_xiong[] = {"胸雄凶兄熊汹匈芎"};
static char PINYIN_mp_xiu[] = {"修锈绣休羞宿嗅袖秀朽臭溴貅馐髹鸺咻庥岫"};
static char PINYIN_mp_xu[] = {"许须需虚嘘蓄续序叙畜絮婿戌徐旭绪吁酗恤墟糈勖栩浒蓿顼圩洫胥醑诩溆煦盱砉"};
static char PINYIN_mp_xuan[] = {"选悬旋玄宣喧轩绚眩癣券暄楦儇渲漩泫铉璇煊碹镟炫揎萱痃谖"};
static char PINYIN_mp_xue[] = {"学雪血靴穴削薛踅噱鳕泶谑彐"};
static char PINYIN_mp_xun[] = {"寻讯熏训循殉旬巡迅驯汛逊勋荤询浚巽鲟浔埙恂獯醺洵郇峋蕈薰荀窨曛徇孙荨"};
static char PINYIN_mp_ya[] = {"呀压牙押芽鸭轧哑亚涯丫雅衙鸦讶蚜垭疋砑琊桠睚娅痖岈氩伢迓揠崖厌吖"};
static char PINYIN_mp_yan[] = {"眼烟沿盐言演严咽淹炎掩厌宴岩研延堰验艳殷阉砚雁唁彦焰蜒衍谚燕颜阎铅焉奄芫厣阏菸魇琰滟焱赝筵腌兖剡餍恹罨檐湮偃谳胭晏闫俨郾酽鄢妍鼹崦阽嫣埏讠"};
static char PINYIN_mp_yang[] = {"样养羊洋仰扬秧氧痒杨漾阳殃央鸯佯疡炀恙徉鞅泱蛘烊怏"};
static char PINYIN_mp_yao[] = {"要摇药咬腰窑舀邀妖谣遥姚瑶耀尧钥侥陶约疟珧夭鳐鹞轺爻吆铫幺崾肴曜徭杳窈么繇"};
static char PINYIN_mp_ye[] = {"也夜业野叶爷页液掖腋冶噎耶咽曳椰邪谒邺晔烨揶铘靥揲"};
static char PINYIN_mp_yi[] = {"一以已亿衣移依易医乙仪亦椅益倚姨翼译伊蛇遗食艾胰疑沂宜异彝壹蚁谊揖铱矣翌艺抑绎邑蛾屹尾役臆逸肄疫颐裔意毅忆义夷溢诣议怿痍镒癔怡驿旖熠酏翊欹峄圯殪嗌咦懿噫劓诒饴漪佚咿瘗猗眙羿弈苡荑仡佾贻钇缢迤刈悒黟翳弋奕蜴埸挹嶷薏呓轶镱舣衤"};
static char PINYIN_mp_yin[] = {"因引印银音饮阴隐荫吟尹寅茵淫殷姻烟堙鄞喑夤胤龈吲圻狺垠霪蚓氤铟窨瘾洇茚廴湮"};
static char PINYIN_mp_ying[] = {"应硬影营迎映蝇赢鹰英颖莹盈婴樱缨荧萤萦楹蓥瘿茔鹦媵莺璎郢嘤撄瑛滢潆嬴罂瀛膺荥颍景"};
static char PINYIN_mp_yo[] = {"哟育唷"};
static char PINYIN_mp_yong[] = {"用涌永拥蛹勇雍咏泳佣踊痈庸臃恿壅慵俑墉鳙邕喁甬饔镛"};
static char PINYIN_mp_you[] = {"有又由右油游幼优友铀忧尤犹诱悠邮酉佑釉幽疣攸蚰莠鱿卣黝莸猷蚴宥牖囿柚蝣莜鼬铕蝤繇呦侑尢"};
static char PINYIN_mp_yu[] = {"与于欲鱼雨余遇语愈狱玉渔予誉育愚羽虞娱淤舆屿禹宇迂俞逾域芋郁谷吁盂喻峪御愉粥渝尉榆隅浴寓裕预豫驭蔚妪嵛雩馀阈窬鹆妤揄窳觎臾舁龉蓣煜钰谀纡於竽瑜禺聿欤俣伛圄鹬庾昱萸瘐谕鬻圉瘀熨饫毓燠腴狳菀蜮蝓吾喁菸肀"};
static char PINYIN_mp_yuan[] = {"远员元院圆原愿园援猿怨冤源缘袁渊苑垣鸳辕圜鼋橼媛爰眢鸢掾芫沅瑗螈箢塬垸"};
static char PINYIN_mp_yue[] = {"月越约跃阅乐岳悦曰说粤钥瀹钺刖龠栎樾哕"};
static char PINYIN_mp_yun[] = {"云运晕允匀韵陨孕耘蕴酝郧员氲恽愠郓芸筠韫昀狁殒纭熨媪菀"};
static char PINYIN_mp_za[] = {"杂砸咋匝扎咱咂拶"};
static char PINYIN_mp_zai[] = {"在再灾载栽宰哉崽甾仔"};
static char PINYIN_mp_zan[] = {"咱暂攒赞簪趱糌瓒拶昝錾"};
static char PINYIN_mp_zang[] = {"脏葬赃藏臧驵奘"};
static char PINYIN_mp_zao[] = {"早造遭糟灶燥枣凿躁藻皂噪澡蚤唣"};
static char PINYIN_mp_ze[] = {"则责择泽咋侧箦舴帻迮啧仄昃笮赜"};
static char PINYIN_mp_zei[] = {"贼"};
static char PINYIN_mp_zen[] = {"怎谮"};
static char PINYIN_mp_zeng[] = {"增赠憎曾综缯罾甑锃"};
static char PINYIN_mp_zha[] = {"扎炸渣闸眨榨乍轧诈喳札铡揸吒咤哳猹砟痄蚱齄查蜡栅咋喋楂柞"};
static char PINYIN_mp_zhai[] = {"摘窄债斋寨择翟宅侧祭砦瘵"};
static char PINYIN_mp_zhan[] = {"站占战盏沾粘毡展栈詹颤蘸湛绽斩辗崭瞻谵搌旃"};
static char PINYIN_mp_zhang[] = {"张章长帐仗丈掌涨账樟杖彰漳胀瘴障仉嫜幛鄣璋嶂獐蟑"};
static char PINYIN_mp_zhao[] = {"找着照招罩爪兆朝昭沼肇嘲召赵棹啁钊笊诏濯"};
static char PINYIN_mp_zhe[] = {"着这者折遮蛰哲蔗锗辙浙柘辄赭摺鹧磔褶蜇谪乇"};
static char PINYIN_mp_zhen[] = {"真阵镇针震枕振斟珍疹诊甄砧臻贞侦缜蓁祯箴轸榛稹赈朕鸩胗浈桢畛圳椹溱"};
static char PINYIN_mp_zheng[] = {"正整睁争挣征怔证症郑拯丁蒸狰政峥钲铮筝诤徵鲭帧"};
static char PINYIN_mp_zhi[] = {"只之直知制指纸支芝枝稚吱蜘质肢脂汁炙织职痔植抵殖执值侄址滞止趾治旨窒志挚掷至致置帜识峙氏智秩帙摭黹桎枳轵忮祉蛭膣觯郅栀彘芷祗咫鸷絷踬胝骘轾痣陟踯雉埴贽卮酯豸跖栉郦夂"};
static char PINYIN_mp_zhong[] = {"中重种钟肿众终盅忠仲衷踵舯螽锺冢忪夂"};
static char PINYIN_mp_zhou[] = {"周洲皱粥州轴舟昼骤宙诌肘帚咒繇胄纣荮啁碡绉籀妯酎"};
static char PINYIN_mp_zhu[] = {"住主猪竹株煮筑贮铸嘱拄注祝驻属术珠瞩蛛朱柱诸诛逐助烛蛀潴洙伫瘃翥茱苎橥舳杼箸炷侏铢疰渚褚躅麈邾槠竺澍丶"};
static char PINYIN_mp_zhua[] = {"抓爪挝"};
static char PINYIN_mp_zhuai[] = {"拽转"};
static char PINYIN_mp_zhuan[] = {"转专砖赚传撰篆颛馔啭沌"};
static char PINYIN_mp_zhuang[] = {"装撞庄壮桩状幢妆僮奘戆"};
static char PINYIN_mp_zhui[] = {"追坠缀锥赘椎骓惴缒隹揣"};
static char PINYIN_mp_zhun[] = {"准谆屯肫窀淳"};
static char PINYIN_mp_zhuo[] = {"捉桌着啄拙灼浊卓琢缴茁酌擢焯濯诼浞涿倬镯禚斫棹淖躅"};
static char PINYIN_mp_zi[] = {"字自子紫籽资姿吱滓仔兹咨孜渍滋淄笫粢龇秭恣谘趑缁梓鲻锱孳耔觜髭赀茈訾嵫眦姊辎甾"};
static char PINYIN_mp_zong[] = {"总纵宗棕综踪鬃偬粽枞腙"};
static char PINYIN_mp_zou[] = {"走揍奏邹鲰鄹陬驺诹楱"};
static char PINYIN_mp_zu[] = {"组族足阻租祖诅菹镞卒俎"};
static char PINYIN_mp_zuan[] = {"钻纂赚攥缵躜"};
static char PINYIN_mp_zui[] = {"最嘴醉罪堆咀觜蕞羧"};
static char PINYIN_mp_zun[] = {"尊遵鳟撙樽奠"};
static char PINYIN_mp_zuo[] = {"做作坐左座昨凿琢撮佐笮酢唑祚胙怍阼柞嘬"};
#endif

struct PINYIN_initials PINYIN_SUMMARY[] = {{"a", PINYIN_mp_a},
    {"ai", PINYIN_mp_ai},
    {"an", PINYIN_mp_an},
    {"ang", PINYIN_mp_ang},
    {"ao", PINYIN_mp_ao},
    {"ba", PINYIN_mp_ba},
    {"bai", PINYIN_mp_bai},
    {"ban", PINYIN_mp_ban},
    {"bang", PINYIN_mp_bang},
    {"bao", PINYIN_mp_bao},
    {"bei", PINYIN_mp_bei},
    {"ben", PINYIN_mp_ben},
    {"beng", PINYIN_mp_beng},
    {"bi", PINYIN_mp_bi},
    {"bian", PINYIN_mp_bian},
    {"biao", PINYIN_mp_biao},
    {"bie", PINYIN_mp_bie},
    {"bin", PINYIN_mp_bin},
    {"bing", PINYIN_mp_bing},
    {"bo", PINYIN_mp_bo},
    {"bu", PINYIN_mp_bu},
    {"ca", PINYIN_mp_ca},
    {"cai", PINYIN_mp_cai},
    {"can", PINYIN_mp_can},
    {"cang", PINYIN_mp_cang},
    {"cao", PINYIN_mp_cao},
    {"ce", PINYIN_mp_ce},
    {"cen", PINYIN_mp_cen},
    {"ceng", PINYIN_mp_ceng},
    {"cha", PINYIN_mp_cha},
    {"chai", PINYIN_mp_chai},
    {"chan", PINYIN_mp_chan},
    {"chang", PINYIN_mp_chang},
    {"chao", PINYIN_mp_chao},
    {"che", PINYIN_mp_che},
    {"chen", PINYIN_mp_chen},
    {"cheng", PINYIN_mp_cheng},
    {"chi", PINYIN_mp_chi},
    {"chong", PINYIN_mp_chong},
    {"chou", PINYIN_mp_chou},
    {"chu", PINYIN_mp_chu},
    {"chuai", PINYIN_mp_chuai},
    {"chuan", PINYIN_mp_chuan},
    {"chuang", PINYIN_mp_chuang},
    {"chui", PINYIN_mp_chui},
    {"chun", PINYIN_mp_chun},
    {"chuo", PINYIN_mp_chuo},
    {"ci", PINYIN_mp_ci},
    {"cong", PINYIN_mp_cong},
    {"cou", PINYIN_mp_cou},
    {"cu", PINYIN_mp_cu},
    {"cuan", PINYIN_mp_cuan},
    {"cui", PINYIN_mp_cui},
    {"cun", PINYIN_mp_cun},
    {"cuo", PINYIN_mp_cuo},
    {"da", PINYIN_mp_da},
    {"dai", PINYIN_mp_dai},
    {"dan", PINYIN_mp_dan},
    {"dang", PINYIN_mp_dang},
    {"dao", PINYIN_mp_dao},
    {"de", PINYIN_mp_de},
    {"dei", PINYIN_mp_dei},
    {"deng", PINYIN_mp_deng},
    {"di", PINYIN_mp_di},
    {"dia", PINYIN_mp_dia},
    {"dian", PINYIN_mp_dian},
    {"diao", PINYIN_mp_diao},
    {"die", PINYIN_mp_die},
    {"ding", PINYIN_mp_ding},
    {"diu", PINYIN_mp_diu},
    {"dong", PINYIN_mp_dong},
    {"dou", PINYIN_mp_dou},
    {"du", PINYIN_mp_du},
    {"duan", PINYIN_mp_duan},
    {"dui", PINYIN_mp_dui},
    {"dun", PINYIN_mp_dun},
    {"duo", PINYIN_mp_duo},
    {"e", PINYIN_mp_e},
    {"ei", PINYIN_mp_ei},
    {"en", PINYIN_mp_en},
    {"er", PINYIN_mp_er},
    {"fa", PINYIN_mp_fa},
    {"fan", PINYIN_mp_fan},
    {"fang", PINYIN_mp_fang},
    {"fei", PINYIN_mp_fei},
    {"fen", PINYIN_mp_fen},
    {"feng", PINYIN_mp_feng},
    {"fo", PINYIN_mp_fo},
    {"fou", PINYIN_mp_fou},
    {"fu", PINYIN_mp_fu},
    {"ga", PINYIN_mp_ga},
    {"gai", PINYIN_mp_gai},
    {"gan", PINYIN_mp_gan},
    {"gang", PINYIN_mp_gang},
    {"gao", PINYIN_mp_gao},
    {"ge", PINYIN_mp_ge},
    {"gei", PINYIN_mp_gei},
    {"gen", PINYIN_mp_gen},
    {"geng", PINYIN_mp_geng},
    {"gong", PINYIN_mp_gong},
    {"gou", PINYIN_mp_gou},
    {"gu", PINYIN_mp_gu},
    {"gua", PINYIN_mp_gua},
    {"guai", PINYIN_mp_guai},
    {"guan", PINYIN_mp_guan},
    {"guang", PINYIN_mp_guang},
    {"gui", PINYIN_mp_gui},
    {"gun", PINYIN_mp_gun},
    {"guo", PINYIN_mp_guo},
    {"ha", PINYIN_mp_ha},
    {"hai", PINYIN_mp_hai},
    {"han", PINYIN_mp_han},
    {"hang", PINYIN_mp_hang},
    {"hao", PINYIN_mp_hao},
    {"he", PINYIN_mp_he},
    {"hei", PINYIN_mp_hei},
    {"hen", PINYIN_mp_hen},
    {"heng", PINYIN_mp_heng},
    {"hong", PINYIN_mp_hong},
    {"hou", PINYIN_mp_hou},
    {"hu", PINYIN_mp_hu},
    {"hua", PINYIN_mp_hua},
    {"huai", PINYIN_mp_huai},
    {"huan", PINYIN_mp_huan},
    {"huang", PINYIN_mp_huang},
    {"hui", PINYIN_mp_hui},
    {"hun", PINYIN_mp_hun},
    {"huo", PINYIN_mp_huo},
    {"ji", PINYIN_mp_ji},
    {"jia", PINYIN_mp_jia},
    {"jian", PINYIN_mp_jian},
    {"jiang", PINYIN_mp_jiang},
    {"jiao", PINYIN_mp_jiao},
    {"jie", PINYIN_mp_jie},
    {"jin", PINYIN_mp_jin},
    {"jing", PINYIN_mp_jing},
    {"jiong", PINYIN_mp_jiong},
    {"jiu", PINYIN_mp_jiu},
    {"ju", PINYIN_mp_ju},
    {"juan", PINYIN_mp_juan},
    {"jue", PINYIN_mp_jue},
    {"jun", PINYIN_mp_jun},
    {"ka", PINYIN_mp_ka},
    {"kai", PINYIN_mp_kai},
    {"kan", PINYIN_mp_kan},
    {"kang", PINYIN_mp_kang},
    {"kao", PINYIN_mp_kao},
    {"ke", PINYIN_mp_ke},
    {"ken", PINYIN_mp_ken},
    {"keng", PINYIN_mp_keng},
    {"kong", PINYIN_mp_kong},
    {"kou", PINYIN_mp_kou},
    {"ku", PINYIN_mp_ku},
    {"kua", PINYIN_mp_kua},
    {"kuai", PINYIN_mp_kuai},
    {"kuan", PINYIN_mp_kuan},
    {"kuang", PINYIN_mp_kuang},
    {"kui", PINYIN_mp_kui},
    {"kun", PINYIN_mp_kun},
    {"kuo", PINYIN_mp_kuo},
    {"la", PINYIN_mp_la},
    {"lai", PINYIN_mp_lai},
    {"lan", PINYIN_mp_lan},
    {"lang", PINYIN_mp_lang},
    {"lao", PINYIN_mp_lao},
    {"le", PINYIN_mp_le},
    {"lei", PINYIN_mp_lei},
    {"leng", PINYIN_mp_leng},
    {"li", PINYIN_mp_li},
    {"lia", PINYIN_mp_lia},
    {"lian", PINYIN_mp_lian},
    {"liang", PINYIN_mp_liang},
    {"liao", PINYIN_mp_liao},
    {"lie", PINYIN_mp_lie},
    {"lin", PINYIN_mp_lin},
    {"ling", PINYIN_mp_ling},
    {"liu", PINYIN_mp_liu},
    {"lo", PINYIN_mp_lo},
    {"long", PINYIN_mp_long},
    {"lou", PINYIN_mp_lou},
    {"lu", PINYIN_mp_lu},
    {"luan", PINYIN_mp_luan},
    {"lue", PINYIN_mp_lue},
    {"lun", PINYIN_mp_lun},
    {"luo", PINYIN_mp_luo},
    {"lv", PINYIN_mp_lv},
    {"ma", PINYIN_mp_ma},
    {"mai", PINYIN_mp_mai},
    {"man", PINYIN_mp_man},
    {"mang", PINYIN_mp_mang},
    {"mao", PINYIN_mp_mao},
    {"me", PINYIN_mp_me},
    {"mei", PINYIN_mp_mei},
    {"men", PINYIN_mp_men},
    {"meng", PINYIN_mp_meng},
    {"mi", PINYIN_mp_mi},
    {"mian", PINYIN_mp_mian},
    {"miao", PINYIN_mp_miao},
    {"mie", PINYIN_mp_mie},
    {"min", PINYIN_mp_min},
    {"ming", PINYIN_mp_ming},
    {"miu", PINYIN_mp_miu},
    {"mo", PINYIN_mp_mo},
    {"mou", PINYIN_mp_mou},
    {"mu", PINYIN_mp_mu},
    {"ma", PINYIN_mp_na},
    {"nai", PINYIN_mp_nai},
    {"nan", PINYIN_mp_nan},
    {"nang", PINYIN_mp_nang},
    {"nao", PINYIN_mp_nao},
    {"ne", PINYIN_mp_ne},
    {"nei", PINYIN_mp_nei},
    {"nen", PINYIN_mp_nen},
    {"neng", PINYIN_mp_neng},
    {"ng", PINYIN_mp_ng},
    {"ni", PINYIN_mp_ni},
    {"nian", PINYIN_mp_nian},
    {"niang", PINYIN_mp_niang},
    {"niao", PINYIN_mp_niao},
    {"nie", PINYIN_mp_nie},
    {"nin", PINYIN_mp_nin},
    {"ning", PINYIN_mp_ning},
    {"niu", PINYIN_mp_niu},
    {"nong", PINYIN_mp_nong},
    {"nou", PINYIN_mp_nou},
    {"nu", PINYIN_mp_nu},
    {"nuan", PINYIN_mp_nuan},
    {"nue", PINYIN_mp_nue},
    {"nuo", PINYIN_mp_nuo},
    {"nv", PINYIN_mp_nv},
    {"o", PINYIN_mp_o},
    {"ou", PINYIN_mp_ou},
    {"pa", PINYIN_mp_pa},
    {"pai", PINYIN_mp_pai},
    {"pan", PINYIN_mp_pan},
    {"pang", PINYIN_mp_pang},
    {"pao", PINYIN_mp_pao},
    {"pei", PINYIN_mp_pei},
    {"pen", PINYIN_mp_pen},
    {"peng", PINYIN_mp_peng},
    {"pi", PINYIN_mp_pi},
    {"pian", PINYIN_mp_pian},
    {"piao", PINYIN_mp_piao},
    {"pie", PINYIN_mp_pie},
    {"pin", PINYIN_mp_pin},
    {"ping", PINYIN_mp_ping},
    {"po", PINYIN_mp_po},
    {"pou", PINYIN_mp_pou},
    {"pu", PINYIN_mp_pu},
    {"qi", PINYIN_mp_qi},
    {"qia", PINYIN_mp_qia},
    {"qian", PINYIN_mp_qian},
    {"qiang", PINYIN_mp_qiang},
    {"qiao", PINYIN_mp_qiao},
    {"qie", PINYIN_mp_qie},
    {"qin", PINYIN_mp_qin},
    {"qing", PINYIN_mp_qing},
    {"qiong", PINYIN_mp_qiong},
    {"qiu", PINYIN_mp_qiu},
    {"qu", PINYIN_mp_qu},
    {"quan", PINYIN_mp_quan},
    {"que", PINYIN_mp_que},
    {"qui", PINYIN_mp_qui},
    {"qun", PINYIN_mp_qun},
    {"ran", PINYIN_mp_ran},
    {"rang", PINYIN_mp_rang},
    {"rao", PINYIN_mp_rao},
    {"re", PINYIN_mp_re},
    {"ren", PINYIN_mp_ren},
    {"reng", PINYIN_mp_reng},
    {"ri", PINYIN_mp_ri},
    {"rong", PINYIN_mp_rong},
    {"rou", PINYIN_mp_rou},
    {"ru", PINYIN_mp_ru},
    {"ruan", PINYIN_mp_ruan},
    {"rui", PINYIN_mp_rui},
    {"run", PINYIN_mp_run},
    {"ruo", PINYIN_mp_ruo},
    {"sa", PINYIN_mp_sa},
    {"sai", PINYIN_mp_sai},
    {"san", PINYIN_mp_san},
    {"sang", PINYIN_mp_sang},
    {"sao", PINYIN_mp_sao},
    {"se", PINYIN_mp_se},
    {"sen", PINYIN_mp_sen},
    {"seng", PINYIN_mp_seng},
    {"sha", PINYIN_mp_sha},
    {"shai", PINYIN_mp_shai},
    {"shan", PINYIN_mp_shan},
    {"shang ", PINYIN_mp_shang},
    {"shao", PINYIN_mp_shao},
    {"she", PINYIN_mp_she},
    {"shei", PINYIN_mp_shei},
    {"shen", PINYIN_mp_shen},
    {"sheng", PINYIN_mp_sheng},
    {"shi", PINYIN_mp_shi},
    {"shou", PINYIN_mp_shou},
    {"shu", PINYIN_mp_shu},
    {"shua", PINYIN_mp_shua},
    {"shuai", PINYIN_mp_shuai},
    {"shuan", PINYIN_mp_shuan},
    {"shuang", PINYIN_mp_shuang},
    {"shui", PINYIN_mp_shui},
    {"shun", PINYIN_mp_shun},
    {"shuo", PINYIN_mp_shuo},
    {"si", PINYIN_mp_si},
    {"song", PINYIN_mp_song},
    {"sou", PINYIN_mp_sou},
    {"su", PINYIN_mp_su},
    {"suan", PINYIN_mp_suan},
    {"sui", PINYIN_mp_sui},
    {"sun", PINYIN_mp_sun},
    {"suo", PINYIN_mp_suo},
    {"ta", PINYIN_mp_ta},
    {"tai", PINYIN_mp_tai},
    {"tan", PINYIN_mp_tan},
    {"tang", PINYIN_mp_tang},
    {"tao", PINYIN_mp_tao},
    {"te", PINYIN_mp_te},
    {"teng", PINYIN_mp_teng},
    {"ti", PINYIN_mp_ti},
    {"tian", PINYIN_mp_tian},
    {"tiao", PINYIN_mp_tiao},
    {"tie", PINYIN_mp_tie},
    {"ting", PINYIN_mp_ting},
    {"tong", PINYIN_mp_tong},
    {"tou", PINYIN_mp_tou},
    {"tu", PINYIN_mp_tu},
    {"tuan", PINYIN_mp_tuan},
    {"tui", PINYIN_mp_tui},
    {"tun", PINYIN_mp_tun},
    {"tuo", PINYIN_mp_tuo},
    {"wa", PINYIN_mp_wa},
    {"wai", PINYIN_mp_wai},
    {"wan", PINYIN_mp_wan},
    {"wang", PINYIN_mp_wang},
    {"wei", PINYIN_mp_wei},
    {"wen", PINYIN_mp_wen},
    {"weng", PINYIN_mp_weng},
    {"wo", PINYIN_mp_wo},
    {"wu", PINYIN_mp_wu},
    {"xi", PINYIN_mp_xi},
    {"xia", PINYIN_mp_xia},
    {"xian", PINYIN_mp_xian},
    {"xiang", PINYIN_mp_xiang},
    {"xiao", PINYIN_mp_xiao},
    {"xie", PINYIN_mp_xie},
    {"xin", PINYIN_mp_xin},
    {"xing", PINYIN_mp_xing},
    {"xiong", PINYIN_mp_xiong},
    {"xiu", PINYIN_mp_xiu},
    {"xu", PINYIN_mp_xu},
    {"xuan", PINYIN_mp_xuan},
    {"xue", PINYIN_mp_xue},
    {"xun", PINYIN_mp_xun},
    {"ya", PINYIN_mp_ya},
    {"yan", PINYIN_mp_yan},
    {"yang", PINYIN_mp_yang},
    {"yao", PINYIN_mp_yao},
    {"ye", PINYIN_mp_ye},
    {"yi", PINYIN_mp_yi},
    {"yin", PINYIN_mp_yin},
    {"ying", PINYIN_mp_ying},
    {"yo", PINYIN_mp_yo},
    {"yong", PINYIN_mp_yong},
    {"you", PINYIN_mp_you},
    {"yu", PINYIN_mp_yu},
    {"yuan", PINYIN_mp_yuan},
    {"yue", PINYIN_mp_yue},
    {"yun", PINYIN_mp_yun},
    {"za", PINYIN_mp_za},
    {"zai", PINYIN_mp_zai},
    {"zan", PINYIN_mp_zan},
    {"zang", PINYIN_mp_zang},
    {"zao", PINYIN_mp_zao},
    {"ze", PINYIN_mp_ze},
    {"zei", PINYIN_mp_zei},
    {"zen", PINYIN_mp_zen},
    {"zeng", PINYIN_mp_zeng},
    {"zha", PINYIN_mp_zha},
    {"zhai", PINYIN_mp_zhai},
    {"zhan", PINYIN_mp_zhan},
    {"zhang", PINYIN_mp_zhang},
    {"zhao", PINYIN_mp_zhao},
    {"zhe", PINYIN_mp_zhe},
    {"zhen", PINYIN_mp_zhen},
    {"zheng", PINYIN_mp_zheng},
    {"zhi", PINYIN_mp_zhi},
    {"zhong", PINYIN_mp_zhong},
    {"zhou", PINYIN_mp_zhou},
    {"zhu", PINYIN_mp_zhu},
    {"zhua", PINYIN_mp_zhua},
    {"zhuai", PINYIN_mp_zhuai},
    {"zhuan", PINYIN_mp_zhuan},
    {"zhuang", PINYIN_mp_zhuang},
    {"zhui", PINYIN_mp_zhui},
    {"zhun", PINYIN_mp_zhun},
    {"zhuo", PINYIN_mp_zhuo},
    {"zi", PINYIN_mp_zi},
    {"zong", PINYIN_mp_zong},
    {"zou", PINYIN_mp_zou},
    {"zu", PINYIN_mp_zu},
    {"zuan", PINYIN_mp_zuan},
    {"zui", PINYIN_mp_zui},
    {"zun", PINYIN_mp_zun},
    {"zuo", PINYIN_mp_zuo}
};
#endif
