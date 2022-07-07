type code =
  | AF
  | AX
  | AL
  | DZ
  | AS
  | AD
  | AO
  | AI
  | AQ
  | AG
  | AR
  | AM
  | AW
  | AU
  | AT
  | AZ
  | BS
  | BH
  | BD
  | BB
  | BY
  | BE
  | BZ
  | BJ
  | BM
  | BT
  | BO
  | BQ
  | BA
  | BW
  | BV
  | BR
  | IO
  | BN
  | BG
  | BF
  | BI
  | KH
  | CM
  | CA
  | CV
  | KY
  | CF
  | TD
  | CL
  | CN
  | CX
  | CC
  | CO
  | KM
  | CG
  | CD
  | CK
  | CR
  | CI
  | HR
  | CU
  | CW
  | CY
  | CZ
  | DK
  | DJ
  | DM
  | DO
  | EC
  | EG
  | SV
  | GQ
  | ER
  | EE
  | ET
  | FK
  | FO
  | FJ
  | FI
  | FR
  | GF
  | PF
  | TF
  | GA
  | GM
  | GE
  | DE
  | GH
  | GI
  | GR
  | GL
  | GD
  | GP
  | GU
  | GT
  | GG
  | GN
  | GW
  | GY
  | HT
  | HM
  | VA
  | HN
  | HK
  | HU
  | IS
  | IN
  | ID
  | IR
  | IQ
  | IE
  | IM
  | IL
  | IT
  | JM
  | JP
  | JE
  | JO
  | KZ
  | KE
  | KI
  | KP
  | KR
  | KW
  | KG
  | LA
  | LV
  | LB
  | LS
  | LR
  | LY
  | LI
  | LT
  | LU
  | MO
  | MK
  | MG
  | MW
  | MY
  | MV
  | ML
  | MT
  | MH
  | MQ
  | MR
  | MU
  | YT
  | MX
  | FM
  | MD
  | MC
  | MN
  | ME
  | MS
  | MA
  | MZ
  | MM
  | NA
  | NR
  | NP
  | NL
  | NC
  | NZ
  | NI
  | NE
  | NG
  | NU
  | NF
  | MP
  | NO
  | OM
  | PK
  | PW
  | PS
  | PA
  | PG
  | PY
  | PE
  | PH
  | PN
  | PL
  | PT
  | PR
  | QA
  | RE
  | RO
  | RU
  | RW
  | BL
  | SH
  | KN
  | LC
  | MF
  | PM
  | VC
  | WS
  | SM
  | ST
  | SA
  | SN
  | RS
  | SC
  | SL
  | SG
  | SX
  | SK
  | SI
  | SB
  | SO
  | ZA
  | GS
  | SS
  | ES
  | LK
  | SD
  | SR
  | SJ
  | SZ
  | SE
  | CH
  | SY
  | TW
  | TJ
  | TZ
  | TH
  | TL
  | TG
  | TK
  | TO
  | TT
  | TN
  | TR
  | TM
  | TC
  | TV
  | UG
  | UA
  | AE
  | GB
  | US
  | UM
  | UY
  | UZ
  | VU
  | VE
  | VN
  | VG
  | VI
  | WF
  | EH
  | YE
  | ZM
  | ZW;

let codeOfString = str => {
  switch (str) {
  | "af" => Some(AF)
  | "ax" => Some(AX)
  | "al" => Some(AL)
  | "dz" => Some(DZ)
  | "as" => Some(AS)
  | "ad" => Some(AD)
  | "ao" => Some(AO)
  | "ai" => Some(AI)
  | "aq" => Some(AQ)
  | "ag" => Some(AG)
  | "ar" => Some(AR)
  | "am" => Some(AM)
  | "aw" => Some(AW)
  | "au" => Some(AU)
  | "at" => Some(AT)
  | "az" => Some(AZ)
  | "bs" => Some(BS)
  | "bh" => Some(BH)
  | "bd" => Some(BD)
  | "bb" => Some(BB)
  | "by" => Some(BY)
  | "be" => Some(BE)
  | "bz" => Some(BZ)
  | "bj" => Some(BJ)
  | "bm" => Some(BM)
  | "bt" => Some(BT)
  | "bo" => Some(BO)
  | "bq" => Some(BQ)
  | "ba" => Some(BA)
  | "bw" => Some(BW)
  | "bv" => Some(BV)
  | "br" => Some(BR)
  | "io" => Some(IO)
  | "bn" => Some(BN)
  | "bg" => Some(BG)
  | "bf" => Some(BF)
  | "bi" => Some(BI)
  | "kh" => Some(KH)
  | "cm" => Some(CM)
  | "ca" => Some(CA)
  | "cv" => Some(CV)
  | "ky" => Some(KY)
  | "cf" => Some(CF)
  | "td" => Some(TD)
  | "cl" => Some(CL)
  | "cn" => Some(CN)
  | "cx" => Some(CX)
  | "cc" => Some(CC)
  | "co" => Some(CO)
  | "km" => Some(KM)
  | "cg" => Some(CG)
  | "cd" => Some(CD)
  | "ck" => Some(CK)
  | "cr" => Some(CR)
  | "ci" => Some(CI)
  | "hr" => Some(HR)
  | "cu" => Some(CU)
  | "cw" => Some(CW)
  | "cy" => Some(CY)
  | "cz" => Some(CZ)
  | "dk" => Some(DK)
  | "dj" => Some(DJ)
  | "dm" => Some(DM)
  | "do" => Some(DO)
  | "ec" => Some(EC)
  | "eg" => Some(EG)
  | "sv" => Some(SV)
  | "gq" => Some(GQ)
  | "er" => Some(ER)
  | "ee" => Some(EE)
  | "et" => Some(ET)
  | "fk" => Some(FK)
  | "fo" => Some(FO)
  | "fj" => Some(FJ)
  | "fi" => Some(FI)
  | "fr" => Some(FR)
  | "gf" => Some(GF)
  | "pf" => Some(PF)
  | "tf" => Some(TF)
  | "ga" => Some(GA)
  | "gm" => Some(GM)
  | "ge" => Some(GE)
  | "de" => Some(DE)
  | "gh" => Some(GH)
  | "gi" => Some(GI)
  | "gr" => Some(GR)
  | "gl" => Some(GL)
  | "gd" => Some(GD)
  | "gp" => Some(GP)
  | "gu" => Some(GU)
  | "gt" => Some(GT)
  | "gg" => Some(GG)
  | "gn" => Some(GN)
  | "gw" => Some(GW)
  | "gy" => Some(GY)
  | "ht" => Some(HT)
  | "hm" => Some(HM)
  | "va" => Some(VA)
  | "hn" => Some(HN)
  | "hk" => Some(HK)
  | "hu" => Some(HU)
  | "is" => Some(IS)
  | "in" => Some(IN)
  | "id" => Some(ID)
  | "ir" => Some(IR)
  | "iq" => Some(IQ)
  | "ie" => Some(IE)
  | "im" => Some(IM)
  | "il" => Some(IL)
  | "it" => Some(IT)
  | "jm" => Some(JM)
  | "jp" => Some(JP)
  | "je" => Some(JE)
  | "jo" => Some(JO)
  | "kz" => Some(KZ)
  | "ke" => Some(KE)
  | "ki" => Some(KI)
  | "kp" => Some(KP)
  | "kr" => Some(KR)
  | "kw" => Some(KW)
  | "kg" => Some(KG)
  | "la" => Some(LA)
  | "lv" => Some(LV)
  | "lb" => Some(LB)
  | "ls" => Some(LS)
  | "lr" => Some(LR)
  | "ly" => Some(LY)
  | "li" => Some(LI)
  | "lt" => Some(LT)
  | "lu" => Some(LU)
  | "mo" => Some(MO)
  | "mk" => Some(MK)
  | "mg" => Some(MG)
  | "mw" => Some(MW)
  | "my" => Some(MY)
  | "mv" => Some(MV)
  | "ml" => Some(ML)
  | "mt" => Some(MT)
  | "mh" => Some(MH)
  | "mq" => Some(MQ)
  | "mr" => Some(MR)
  | "mu" => Some(MU)
  | "yt" => Some(YT)
  | "mx" => Some(MX)
  | "fm" => Some(FM)
  | "md" => Some(MD)
  | "mc" => Some(MC)
  | "mn" => Some(MN)
  | "me" => Some(ME)
  | "ms" => Some(MS)
  | "ma" => Some(MA)
  | "mz" => Some(MZ)
  | "mm" => Some(MM)
  | "na" => Some(NA)
  | "nr" => Some(NR)
  | "np" => Some(NP)
  | "nl" => Some(NL)
  | "nc" => Some(NC)
  | "nz" => Some(NZ)
  | "ni" => Some(NI)
  | "ne" => Some(NE)
  | "ng" => Some(NG)
  | "nu" => Some(NU)
  | "nf" => Some(NF)
  | "mp" => Some(MP)
  | "no" => Some(NO)
  | "om" => Some(OM)
  | "pk" => Some(PK)
  | "pw" => Some(PW)
  | "ps" => Some(PS)
  | "pa" => Some(PA)
  | "pg" => Some(PG)
  | "py" => Some(PY)
  | "pe" => Some(PE)
  | "ph" => Some(PH)
  | "pn" => Some(PN)
  | "pl" => Some(PL)
  | "pt" => Some(PT)
  | "pr" => Some(PR)
  | "qa" => Some(QA)
  | "re" => Some(RE)
  | "ro" => Some(RO)
  | "ru" => Some(RU)
  | "rw" => Some(RW)
  | "bl" => Some(BL)
  | "sh" => Some(SH)
  | "kn" => Some(KN)
  | "lc" => Some(LC)
  | "mf" => Some(MF)
  | "pm" => Some(PM)
  | "vc" => Some(VC)
  | "ws" => Some(WS)
  | "sm" => Some(SM)
  | "st" => Some(ST)
  | "sa" => Some(SA)
  | "sn" => Some(SN)
  | "rs" => Some(RS)
  | "sc" => Some(SC)
  | "sl" => Some(SL)
  | "sg" => Some(SG)
  | "sx" => Some(SX)
  | "sk" => Some(SK)
  | "si" => Some(SI)
  | "sb" => Some(SB)
  | "so" => Some(SO)
  | "za" => Some(ZA)
  | "gs" => Some(GS)
  | "ss" => Some(SS)
  | "es" => Some(ES)
  | "lk" => Some(LK)
  | "sd" => Some(SD)
  | "sr" => Some(SR)
  | "sj" => Some(SJ)
  | "sz" => Some(SZ)
  | "se" => Some(SE)
  | "ch" => Some(CH)
  | "sy" => Some(SY)
  | "tw" => Some(TW)
  | "tj" => Some(TJ)
  | "tz" => Some(TZ)
  | "th" => Some(TH)
  | "tl" => Some(TL)
  | "tg" => Some(TG)
  | "tk" => Some(TK)
  | "to" => Some(TO)
  | "tt" => Some(TT)
  | "tn" => Some(TN)
  | "tr" => Some(TR)
  | "tm" => Some(TM)
  | "tc" => Some(TC)
  | "tv" => Some(TV)
  | "ug" => Some(UG)
  | "ua" => Some(UA)
  | "ae" => Some(AE)
  | "gb" => Some(GB)
  | "us" => Some(US)
  | "um" => Some(UM)
  | "uy" => Some(UY)
  | "uz" => Some(UZ)
  | "vu" => Some(VU)
  | "ve" => Some(VE)
  | "vn" => Some(VN)
  | "vg" => Some(VG)
  | "vi" => Some(VI)
  | "wf" => Some(WF)
  | "eh" => Some(EH)
  | "ye" => Some(YE)
  | "zm" => Some(ZM)
  | "zw" => Some(ZW)
  | _ => None
  };
};

let stringOfCode = (c: code): string => {
  switch (c) {
  | AF => "af"
  | AX => "ax"
  | AL => "al"
  | DZ => "dz"
  | AS => "as"
  | AD => "ad"
  | AO => "ao"
  | AI => "ai"
  | AQ => "aq"
  | AG => "ag"
  | AR => "ar"
  | AM => "am"
  | AW => "aw"
  | AU => "au"
  | AT => "at"
  | AZ => "az"
  | BS => "bs"
  | BH => "bh"
  | BD => "bd"
  | BB => "bb"
  | BY => "by"
  | BE => "be"
  | BZ => "bz"
  | BJ => "bj"
  | BM => "bm"
  | BT => "bt"
  | BO => "bo"
  | BQ => "bq"
  | BA => "ba"
  | BW => "bw"
  | BV => "bv"
  | BR => "br"
  | IO => "io"
  | BN => "bn"
  | BG => "bg"
  | BF => "bf"
  | BI => "bi"
  | KH => "kh"
  | CM => "cm"
  | CA => "ca"
  | CV => "cv"
  | KY => "ky"
  | CF => "cf"
  | TD => "td"
  | CL => "cl"
  | CN => "cn"
  | CX => "cx"
  | CC => "cc"
  | CO => "co"
  | KM => "km"
  | CG => "cg"
  | CD => "cd"
  | CK => "ck"
  | CR => "cr"
  | CI => "ci"
  | HR => "hr"
  | CU => "cu"
  | CW => "cw"
  | CY => "cy"
  | CZ => "cz"
  | DK => "dk"
  | DJ => "dj"
  | DM => "dm"
  | DO => "do"
  | EC => "ec"
  | EG => "eg"
  | SV => "sv"
  | GQ => "gq"
  | ER => "er"
  | EE => "ee"
  | ET => "et"
  | FK => "fk"
  | FO => "fo"
  | FJ => "fj"
  | FI => "fi"
  | FR => "fr"
  | GF => "gf"
  | PF => "pf"
  | TF => "tf"
  | GA => "ga"
  | GM => "gm"
  | GE => "ge"
  | DE => "de"
  | GH => "gh"
  | GI => "gi"
  | GR => "gr"
  | GL => "gl"
  | GD => "gd"
  | GP => "gp"
  | GU => "gu"
  | GT => "gt"
  | GG => "gg"
  | GN => "gn"
  | GW => "gw"
  | GY => "gy"
  | HT => "ht"
  | HM => "hm"
  | VA => "va"
  | HN => "hn"
  | HK => "hk"
  | HU => "hu"
  | IS => "is"
  | IN => "in"
  | ID => "id"
  | IR => "ir"
  | IQ => "iq"
  | IE => "ie"
  | IM => "im"
  | IL => "il"
  | IT => "it"
  | JM => "jm"
  | JP => "jp"
  | JE => "je"
  | JO => "jo"
  | KZ => "kz"
  | KE => "ke"
  | KI => "ki"
  | KP => "kp"
  | KR => "kr"
  | KW => "kw"
  | KG => "kg"
  | LA => "la"
  | LV => "lv"
  | LB => "lb"
  | LS => "ls"
  | LR => "lr"
  | LY => "ly"
  | LI => "li"
  | LT => "lt"
  | LU => "lu"
  | MO => "mo"
  | MK => "mk"
  | MG => "mg"
  | MW => "mw"
  | MY => "my"
  | MV => "mv"
  | ML => "ml"
  | MT => "mt"
  | MH => "mh"
  | MQ => "mq"
  | MR => "mr"
  | MU => "mu"
  | YT => "yt"
  | MX => "mx"
  | FM => "fm"
  | MD => "md"
  | MC => "mc"
  | MN => "mn"
  | ME => "me"
  | MS => "ms"
  | MA => "ma"
  | MZ => "mz"
  | MM => "mm"
  | NA => "na"
  | NR => "nr"
  | NP => "np"
  | NL => "nl"
  | NC => "nc"
  | NZ => "nz"
  | NI => "ni"
  | NE => "ne"
  | NG => "ng"
  | NU => "nu"
  | NF => "nf"
  | MP => "mp"
  | NO => "no"
  | OM => "om"
  | PK => "pk"
  | PW => "pw"
  | PS => "ps"
  | PA => "pa"
  | PG => "pg"
  | PY => "py"
  | PE => "pe"
  | PH => "ph"
  | PN => "pn"
  | PL => "pl"
  | PT => "pt"
  | PR => "pr"
  | QA => "qa"
  | RE => "re"
  | RO => "ro"
  | RU => "ru"
  | RW => "rw"
  | BL => "bl"
  | SH => "sh"
  | KN => "kn"
  | LC => "lc"
  | MF => "mf"
  | PM => "pm"
  | VC => "vc"
  | WS => "ws"
  | SM => "sm"
  | ST => "st"
  | SA => "sa"
  | SN => "sn"
  | RS => "rs"
  | SC => "sc"
  | SL => "sl"
  | SG => "sg"
  | SX => "sx"
  | SK => "sk"
  | SI => "si"
  | SB => "sb"
  | SO => "so"
  | ZA => "za"
  | GS => "gs"
  | SS => "ss"
  | ES => "es"
  | LK => "lk"
  | SD => "sd"
  | SR => "sr"
  | SJ => "sj"
  | SZ => "sz"
  | SE => "se"
  | CH => "ch"
  | SY => "sy"
  | TW => "tw"
  | TJ => "tj"
  | TZ => "tz"
  | TH => "th"
  | TL => "tl"
  | TG => "tg"
  | TK => "tk"
  | TO => "to"
  | TT => "tt"
  | TN => "tn"
  | TR => "tr"
  | TM => "tm"
  | TC => "tc"
  | TV => "tv"
  | UG => "ug"
  | UA => "ua"
  | AE => "ae"
  | GB => "gb"
  | US => "us"
  | UM => "um"
  | UY => "uy"
  | UZ => "uz"
  | VU => "vu"
  | VE => "ve"
  | VN => "vn"
  | VG => "vg"
  | VI => "vi"
  | WF => "wf"
  | EH => "eh"
  | YE => "ye"
  | ZM => "zm"
  | ZW => "zw"
  };
};
