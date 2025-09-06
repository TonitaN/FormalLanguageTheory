# TFL
Материалы курса теория формальных языков разных лет.

В материалах 2021-2023 годов лекции организованы не в соответствии плану обновлённой версии 2024 года. 

Рекомендуемая литература по автоматам: Хопкрофт, Эспарца (см. директория 2023, файл `Esparza_autoskript.pdf`), а также лекции ИТМО.

# Важно!

Если вы всё-таки решите начать с просмотра индусов - имейте в виду, они кое-что умалчивают или упрощают, поэтому сначала индусы, а потом всё-таки читаем конспекты ИТМО и Хопкрофта.

Вспомогательные ресурсы:

- [Классический учебник по теории автоматов и языков (Хопркрофт, и др.)]([https://www-2.dc.uba.ar/staff/becher/Hopcroft-Motwani-Ullman-2001.pdf])
- [On the security of the ping-pong protocols. D.Dolev, S. Even, M. Karp](https://www.sciencedirect.com/science/article/pii/S0019995882904016)
- [Mathematical Foundations of Automata Theory. J.-E. Pin](https://www.irif.fr/~jep/PDF/MPRI/MPRI.pdf)
- [A Taste of Rewrite Systems. N.Dershowitz](https://www.cs.tau.ac.il/~nachum/papers/taste-fixed.pdf)
- [Total Termination of Term Rewriting. H.Zantema, M.Ferreira](https://research.tue.nl/files/4285313/398276.pdf)
- [ординальный калькулятор + интерактивный прувер в ординальной ФуМА (ВКР Александра Пискунова, ИУ9)](https://github.com/Vigorge/provskell)
- [проверка эквивалентности регулярок](https://bakkot.github.io/dfa-lib/regeq.html)
- [LL(1)-разбор онлайн (навязывается приоритет разбора)](https://www.cs.princeton.edu/courses/archive/spring20/cos320/LL1/)
- [LR(0)-разбор онлайн (с добавлением эндмаркера)](https://www.cs.princeton.edu/courses/archive/spring20/cos320/LR0/)
- [конспекты лекций ИТМО по ТФЯ (тут есть весь минимум вплоть до LL- и LR-языков)](https://neerc.ifmo.ru/wiki/index.php?title=%D0%A2%D0%B5%D0%BE%D1%80%D0%B8%D1%8F_%D1%84%D0%BE%D1%80%D0%BC%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D1%85_%D1%8F%D0%B7%D1%8B%D0%BA%D0%BE%D0%B2)
- [Лекция Охотина про LL-языки](https://users.math-cs.spbu.ru/~okhotin/teaching/fg_2019/okhotin_fg_2019_l12.pdf)
- [Продолжение лекции Охотина](https://users.math-cs.spbu.ru/~okhotin/teaching/fg_2019/okhotin_fg_2019_l13.pdf)
- [Статья Волкова про синхронизирующиеся автоматы (http)](http://kadm.kmath.ru/files/synchro1.pdf)
- [...а это его же темы курсачей (просто чтобы была возможность сравнить себя с кафедрами теор.инф. провинциальных вузов :) ) - простите, не удержалась](http://kadm.kmath.ru/pages.php?id=volkov_papers) 
- [Анализатор КС-грамматик онлайн (3 в 1: LL(1), LR(0-1), неоднозначность)](https://mdaines.github.io/grammophone/#/)
- [Интерактивный тестировщик пользовательской КС-грамматики](https://web.stanford.edu/class/archive/cs/cs103/cs103.1156/tools/cfg/)

# Дальше идут исключительно труды студентов кафедры ИУ9

- [fuzz-алгоритм, определяющий неоднозначности в расширенных регулярных выражениях, посредством построения их описания в мультиобразцах (ВКР Юлии Беликовой)](https://github.com/julia-bel/regex_fuzzing)
- [Быстрое сопоставление с расширенными регулярными выражениями посредством построения MFA и алгебраических преобразований (ВКР Дарьи Исмагиловой)](https://github.com/Danya-Is/re2-modification)
- [GLR-разбор конъюнктивных грамматик Охотина + синтаксически управляемая интерпретация получившегося SPPF (ВКР Ильи Щербакова, ИУ9)](https://github.com/ylyxa/Conjunctive-GLR) 
- [Конвертер автоматов и регулярок с порождением пошагового описания преобразований в latex (А.Дельман, А.Ильин, Д.Князихин, А.Терентьева, М.Терюха, К.Шевченко и др.)](https://github.com/StarikTenger/Chipollino)
- [Ещё один конвертер, с базовым логированием, но зато в master и без необходимости долгой установки (Ю.Проскурников и компания)](https://github.com/Qmask26/converter_team_project)
- [ГНФ-конвертер КС-грамматик (два алгоритма) (И.Павлов, там ещё унификация по соседству)](https://github.com/boomb0om/FormalLanguageTheory/tree/main/lab3)
- [Построение трансформационного моноида по автомату (А.Иванов, там ещё Кнут-Бендикс и кое-что ещё интересное по соседству)](https://github.com/UsefulTornado/Formal-Languages)
- [Порождение случайных грамматик в пользовательском синтаксисе (полезно для тестирования) (И.Павлов, П.Константинова)](https://github.com/pollykon/FLT_lab5)
- [Построение коммутативного образа КС-грамматики и его описания в векторах (Ю.Петряев) и другие хорошие лабы](https://github.com/p0rtale/tfl-labs/tree/main/lab3)
- [Построение регулярной аппроксимации КС-грамматики по Мори-Недерхопфу (Е. Матвеев и к, ACHTUNG!, лежит в ветке, а не в main)](https://github.com/theElusiveJoe/TFL-rk1-volki_team)
- [Построение аппроксимации AST и другое (А.Котов)](https://github.com/Ankalot/FLT-labs)
- [Построение SLR-автомата и другое (Б.Степанов)](https://github.com/Lasadaf/FLT_labs)

Анти-Доктор:

- [5 вариант РК1 (дополняется)](https://github.com/t1d333/TFL/tree/main/RK1)
- [6 вариант РК2 прошлого года (только одна задача)](https://github.com/theElusiveJoe/BMSTU-IU9/blob/main/Formal%20Language%20Theory/rk2_my.pdf)
- [Мегасхема решения задач из второго РК прошлого года (на баллы не смотрим, но сама схема может пригодиться)](https://github.com/p0rtale/tfl-labs/blob/main/theory/cfl_theory.png)

Если кто-то знает, где лежат красиво написанные решения задач по ТФЯ какого-либо года, хоть какой-то вариант, я сюда добавлю, для нынешнего и будущих поколений (а возможно, пару вариантов разберу тоже письменно).
