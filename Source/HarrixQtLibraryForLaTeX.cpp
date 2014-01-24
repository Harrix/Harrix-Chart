//HarrixQtLibraryForLaTeX
//Версия 1.19
//Библиотека для отображения различных данных в LaTeX файлах.
//https://github.com/Harrix/HarrixQtLibraryForLaTeX
//Библиотека распространяется по лицензии Apache License, Version 2.0.

#include "HarrixQtLibraryForLaTeX.h"

QString HQt_LatexBegin()
{
    /*
     Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//--------------------------------------------------------------------------

QString HQt_LatexBeginWithPgfplots()
{
    /*
     Возвращает начало для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate
     с использованием графиков через пакет pgfplots.
     */
    QString VMHL_Result;
    VMHL_Result+="\\documentclass[a4paper,12pt]{report}\n\n";
    VMHL_Result+="\\input{packages} %Подключаем модуль пакетов\n";
    VMHL_Result+="\\input{styles} %Подключаем модуль стилей\n\n";
    VMHL_Result+="\\usepgfplotslibrary{external}\n";
    VMHL_Result+="\\tikzexternalize[prefix=TikzPictures/]\n\n";
    VMHL_Result+="\\begin{document}\n\n";
    VMHL_Result+="\\input{names} %Подключаем модуль переименования некоторых команд\n\n";

    return VMHL_Result;
}
//--------------------------------------------------------------------------

QString HQt_LatexEnd()
{
    /*
     Возвращает концовку для полноценного Latex файла для шаблона https://github.com/Harrix/HarrixLaTeXDocumentTemplate.
     */
    return "\n\n\\end{document}";
}
//--------------------------------------------------------------------------

QString HQt_LatexShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой (в виде абзаца).
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textbf{"+TitleX+".}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишества.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+String+"\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowHr ()
{
    /*
    Функция возвращает строку с выводом горизонтальной линии.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами с тэгом горизонтальной линии.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\hrulefill\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\section{"+String+"}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowSubsection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде подзаголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\subsection{"+String+"}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым предупреждением.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textcolor{red}{\\textbf{"+String+"}}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginCompositionFigure ()
{
    /*
    Функция возвращает строку с выводом начала рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     Отстуствтует.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\n\\begin{figure}[H]\n\\centering\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndCompositionFigure (QString TitleFigure, QString Label)
{
    /*
    Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     TitleFigure - заголовок рисунка;
     Label - label для рисунка.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\n\\caption{"+TitleFigure+"}\\label{"+Label+"}\\end{figure}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndCompositionFigure (QString TitleFigure)
{
    /*
    Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     TitleFigure - заголовок рисунка.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString Label="CompositionFigure"+HQt_RandomString(5);

    QString VMHL_Result;

    VMHL_Result=HQt_LatexEndCompositionFigure (TitleFigure, Label);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndCompositionFigure ()
{
    /*
    Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString Label="CompositionFigure"+HQt_RandomString(5);

    QString TitleFigure="Система";

    QString VMHL_Result;

    VMHL_Result=HQt_LatexEndCompositionFigure (TitleFigure, Label);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexBeginFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом при добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отстуствтует.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\\begin{subfigure}[t]{0.48\\textwidth}\n\\centering\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexEndFigureInCompositionFigure ()
{
    /*
    Функция возвращает строку с Latex кодом после добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.
    Входные параметры:
     Отстуствтует.
    Возвращаемое значение:
     Строка с Latex кодами.
    Пример использования:
    Latex += HQt_LatexBeginCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot1",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexBeginFigureInCompositionFigure ();
    Latex += THQt_LatexShowChartOfLine (dataX,dataY,N,"Тестовый график","u, Вероятность выбора","q, Количество воронов","линия","plot2",true,true,true,true,false,false);
    Latex += HQt_LatexEndFigureInCompositionFigure ();
    Latex += HQt_LatexEndCompositionFigure ("Два графика", "TwoFig");
    */
    QString VMHL_Result;

    VMHL_Result="\n\\end{subfigure}\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameLine - название первого графика (для легенды);
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    int N=(Right-Left)/h;
    double *dataX=new double [N];
    double *dataY=new double [N];

    double x=Left;
    for (int i=0;i<N;i++)
    {
        dataX[i]=x;
        dataY[i]=Function(x);

        x+=h;
    }

    VMHL_Result += THQt_LatexShowChartOfLine (dataX, dataY, N, TitleChart, NameVectorX, NameVectorY, NameLine, "Chart"+HQt_RandomString(8), ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine, true);

    delete []dataX;
    delete []dataY;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, bool ShowLine, bool ShowPoints, bool ShowArea, bool ShowSpecPoints, bool RedLine)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function. Для добавление в Latex файл.
    Отличается от основной функцией отсутствием параметра NameLine(название графика (для легенды)).
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_LatexDrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, "", ShowLine, ShowPoints, ShowArea, ShowSpecPoints, RedLine);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double), QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameLine)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function. Для добавление в Latex файл.
    Отличается от основной функцией отсутствием булевских параметров в конце - все по умолчанию делается.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_LatexDrawLine (Left, Right, h, Function, TitleChart, NameVectorX, NameVectorY, NameLine, true, false, false, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_LatexDrawLine (double Left, double Right, double h, double (*Function)(double))
{
    /*
    Функция возвращает строку с Latex кодом отрисовки линии по функции Function. Для добавление в Latex файл.
    Отличается от основной функцией отсутствием булевских параметров в конце и названий осей и графиков - для быстрого отображения графика без лишних телодвижений.
    Входные параметры:
     Left - левая граница области;
     Right - правая граница области;
     h - шаг, с которым надо рисовать график;
     Function - указатель на вычисляемую функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     ShowLine - показывать ли линию;
     ShowPoints - показывать ли точки;
     ShowArea - показывать ли закрашенную область под кривой;
     ShowSpecPoints - показывать ли специальные точки;
     RedLine - рисовать ли красную линию, или синюю.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    VMHL_Result += HQt_LatexDrawLine (Left, Right, h, Function, "", "x", "y", true, false, false, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, double Opacity, double AngleHorizontal, double AngleVertical, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     Opacity - прозначность графика. Может изменяться от 0 до 1;
     AngleHorizontal - угол поворота графика по горизонтали в градусах от -180 до 180. Рекомендуется 25;
     AngleVertical - угол поворота графика по вертикали в градусах от -180 до 180. Рекомендуется 30;
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double *x=new double [N];
    double *y=new double [N];
    double **z;
    z=new double*[N];
    for (int i=0;i<N;i++) z[i]=new double[N];

    for (int i=0;i<N;i++)
        x[i]=Left_X + i*(Right_X-Left_X)/double(N-1);
    for (int j=0;j<N;j++)
        y[j]=Left_Y + j*(Right_Y-Left_Y)/double(N-1);

    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
        {
            z[i][j]=Function(x[i],y[j]);
        }

    VMHL_Result = THQt_LatexShow3DPlot (x, y, z,  N,  N, TitleChart,  NameVectorX, NameVectorY, NameVectorZ, Label, ColorMap, Type, Opacity, AngleHorizontal, AngleVertical, ColorBar,  ForNormalSize);

    delete [] x;
    delete [] y;
    for (int i=0;i<N;i++) delete [] z[i];
    delete [] z;

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar, bool ForNormalSize)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет;
     ForNormalSize - нормальный размер графика (на всю ширину), или для маленького размера график создается.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar, ForNormalSize);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type, bool ColorBar)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху;
     ColorBar - рисоватm с графиком колонку с градациями цветов или нет.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, ColorBar, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label, QString ColorMap, TypeOf3DPlot Type)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical, ForNormalSize и ColorBar.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика;
     ColorMap - какой раскраски будет график. Возможны значения: mathcad, matlab, hot или тот, что вы хотите использовать. Рекомендуется mathcad;
     Type - тип графика. Возможные значения:
        Plot3D_Points - в виде точек,
        Plot3D_Surface - в виде поверхности с непрерывной заливкой,
        Plot3D_SurfaceGrid - в виде поверхности с сеточной заливкой,
        Plot3D_TopView - вид сверху.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;
    if (Type==Plot3D_TopView)
    {
       AngleHorizontalNew=0;
       AngleVerticalNew=0;
    }

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, ColorMap, Type, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double),  QString TitleChart, QString NameVectorX, QString NameVectorY, QString NameVectorZ, QString Label)
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют параметры Opacity, AngleHorizontal, AngleVertical и ForNormalSize, ColorBar, ColorMap, Type.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию;
     TitleChart - заголовок графика;
     NameVectorX - название оси Ox. В формате: [обозначение], [расшифровка]. Например: u, Вероятность выбора;
     NameVectorY - название оси Oy. В формате: [обозначение], [расшифровка]. Например: q, Количество абрикосов;
     NameVectorZ - название оси Oz. В формате: [обозначение], [расшифровка]. Например: z, Вероятность;
     Label - label для графика.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  TitleChart, NameVectorX,  NameVectorY, NameVectorZ, Label, "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left_X, double Right_X, double Left_Y, double Right_Y, int N, double (*Function)(double, double))
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют все дополнительные параметры.
    Входные параметры:
     Left_X - левая граница по оси Ox;
     Right_X - правая граница по оси Ox;
     Left_Y - левая граница по оси Oy;
     Right_Y - правая граница по оси Oy;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VMHL_Result = THQt_LatexDraw3DPlot (Left_X, Right_X, Left_Y, Right_Y, N, Function,  "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexDraw3DPlot (double Left, double Right, int N, double (*Function)(double, double))
{
    /*
    Функция возвращает строку с Latex кодом отрисовки 3D поверхности по функции Function.
    По сравнению с основным сайтом отсутствуют все дополнительные параметры и для всех осей одинаковые границы изменения.
    Входные параметры:
     Left - левая граница по осям;
     Right - правая граница по осям;
     N - сколько нужно построить точек по каждой оси. В итоге получим N*N точек;
     Function - ссылка на отрисовываемую двумерную функцию.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым графиком.
    */
    QString VMHL_Result;//переменная итогового результата

    double AngleHorizontalNew=25;
    double AngleVerticalNew=30;

    VMHL_Result = THQt_LatexDraw3DPlot (Left, Right, Left, Right, N, Function,  "График", "x", "y", "z", "Plot3D"+HQt_RandomString(8), "mathcad", Plot3D_Surface, 1.0, AngleHorizontalNew, AngleVerticalNew, true, true);

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleVector+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameVector+"} = ";

    VMHL_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="\\text{"+(VMHL_Vector.at(i))+"}\\\\";
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowVector (QStringList VMHL_Vector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameVector+"} = ";

    VMHL_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="\\text{"+(VMHL_Vector.at(i))+"}\\\\";
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowVector (QStringList VMHL_Vector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    VMHL_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VMHL_Vector.count();i++)
    {
        VMHL_Result+="\\text{"+(VMHL_Vector.at(i))+"}\\\\";
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleMatrix+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------

QString HQt_ReadHdataToLatexChart (QString filename)
{
    /*
    Функция возвращает строку с Latex кодом графика в результате считывания информации из *.hdata версии Harrix Data 1.0.
    Входные параметры:
     filename - имя файла.
    Возвращаемое значение:
     Строка с Latex кодом.
    */
    QString VMHL_Result;

    try
    {
        if (HQt_GetExpFromFilename(filename)!="hdata")
        {
            VMHL_Result+=HQt_LatexShowAlert ("Расширение файла не *.hdata.");
            return VMHL_Result;
        }
        if (!HQt_FileExists(filename))
        {
            VMHL_Result+=HQt_LatexShowAlert ("Файл отсутствует.");
            return VMHL_Result;
        }

        QStringList List = HQt_ReadFileToQStringList(filename);

        if (List.isEmpty())
        {
            VMHL_Result+=HQt_LatexShowAlert ("Файл пустой.");
            return VMHL_Result;
        }

        QString String;

        String=List.at(0);

        if (HQt_TextBeforeEqualSign (String)!="HarrixFileFormat")
        {
            VMHL_Result+=HQt_LatexShowAlert ("Это не формат HarrixFileFormat.");
            return VMHL_Result;
        }
        if ((HQt_TextAfterEqualSign (String)!="Harrix Data 1.1")&&(HQt_TextAfterEqualSign (String)!="Harrix Data 1.0"))
        {
            VMHL_Result+=HQt_LatexShowAlert ("Это не версия Harrix Data 1.0 или 1.1.");
            return VMHL_Result;
        }

        List.removeFirst();
        String=List.at(0);

        if (HQt_TextBeforeEqualSign (String)!="Site")
        {
            VMHL_Result+=HQt_LatexShowAlert ("Ошибка в структуре файла: нет второй строки в виде ссылки на сайт.");
            return VMHL_Result;
        }
        if (HQt_TextAfterEqualSign (String)!="https://github.com/Harrix/HarrixFileFormats")
        {
            VMHL_Result+=HQt_LatexShowAlert ("Ошибка в структуре файла: сайт указан неверно во второй строке.");
            return VMHL_Result;
        }

        //параметры по умолчанию
        QString Type;
        QString Title;
        QString AxisX;
        QString AxisY;
        QString AxisZ;
        bool ShowLine=false;
        bool ShowPoints=false;
        bool ShowArea=false;
        bool ShowSpecPoints=false;
        bool RedLine=false;
        bool MinZero=false;

        //предварительные переменные
        QString TempType;
        QString TempTitle;
        QString TempAxisX;
        QString TempAxisY;
        QString TempAxisZ;
        QString TempParameters;

        QString After;
        QString Before;

        List.removeFirst();

        //проанализируем строчки на наличие тех переменных, которые могут быть необязательными
        int i=0;
        int n=List.count();
        while ((i<n)&&(String!="BeginNamesOfCharts")&&(String!="BeginData"))
        {
            String = List.at(i);
            Before = HQt_TextBeforeEqualSign (String);
            After  = HQt_TextAfterEqualSign (String);

            if (Before=="Type") TempType=After;
            if (Before=="Title") TempTitle=After;
            if (Before=="AxisX") TempAxisX=After;
            if (Before=="AxisY") TempAxisY=After;
            if (Before=="AxisZ") TempAxisZ=After;
            if (Before=="Parameters") TempParameters=After;
            i++;
        }

        for (int j=0;j<i-1;j++) List.removeFirst();//удалим строчки, которые проанализировали

        //А теперь сами переменные проанализируем
        Title=TempTitle;
        AxisX=TempAxisX;
        AxisY=TempAxisY;
        AxisZ=TempAxisZ;

        if (TempType=="Line") Type="Line";
        if (TempType=="TwoLines") Type="TwoLines";
        if (TempType=="TwoIndependentLines") Type="TwoIndependentLines";
        if (TempType=="SeveralIndependentLines") Type="SeveralIndependentLines";
        if (TempType=="SeveralLines") Type="SeveralLines";
        if (TempType=="PointsAndLine") Type="PointsAndLine";
        if (TempType=="Bar") Type="Bar";
        if (TempType=="3DPoints") Type="3DPoints";

        QStringList ListParameters = TempParameters.split( ",", QString::SkipEmptyParts );
        for (int j=0;j<ListParameters.count();j++)
        {
            String=ListParameters.at(j);
            String=String.trimmed();
            if (String=="ShowLine") ShowLine=true;
            if (String=="ShowPoints") ShowPoints=true;
            if (String=="ShowArea") ShowArea=true;
            if (String=="ShowSpecPoints") ShowSpecPoints=true;
            if (String=="RedLine") RedLine=true;
            if (String=="MinZero") MinZero=true;
        }

        if ((ShowLine==false)&&(ShowPoints==false)) ShowLine=true;


        //Теперь пытаемся поискать и обработать названия столбцов
        QStringList ListNamesOfCharts;
        String=List.at(0);
        i=0;
        if (String=="BeginNamesOfCharts")
        {
            int n=List.count();
            while ((i<n)&&(String!="EndNamesOfCharts")&&(String!="BeginData"))
            {
                String = List.at(i);

                if ((String!="BeginNamesOfCharts")&&(String!="EndNamesOfCharts")&&(String!="BeginData")&&(String!="EndData"))
                    ListNamesOfCharts << String;

                i++;
            }
        }

        for (int j=0;j<i;j++) List.removeFirst();//удалим строчки, которые проанализировали

        //Заберем данные непосредственно из файла
        String=List.at(0);
        if (String=="BeginData")
        {

            if (List.at(List.count()-1)!="EndData")
            {
                VMHL_Result+=HQt_LatexShowAlert ("Ошибка в структуре файла: нет в конце строчки EndData.");
                return VMHL_Result;
            }
            List.removeFirst();
            List.removeLast();
            //теперь в List находитсz только нормальный объем данных
        }
        else
        {
            VMHL_Result+=HQt_LatexShowAlert ("Ошибка в структуре файла: нет строчки BeginData.");
            return VMHL_Result;
        }

        //Теперь можем наконец работать с выводом графиков согласно типу
        if (Type=="Line")
        {
            int N=HQt_CountOfRowsFromQStringList(List);
            double *dataX=new double [N];
            double *dataY=new double [N];
            THQt_ReadTwoVectorFromQStringList(List,dataX,dataY);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";

            VMHL_Result += THQt_LatexShowChartOfLine (dataX,dataY,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints,RedLine,true);

            delete []dataX;
            delete []dataY;
        }
        if (Type=="TwoLines")
        {
            int N=HQt_CountOfRowsFromQStringList(List);
            double *dataX=new double [N];
            double *dataY1=new double [N];
            double *dataY2=new double [N];

            THQt_ReadColFromQStringList(List,0,dataX);
            THQt_ReadColFromQStringList(List,1,dataY1);
            THQt_ReadColFromQStringList(List,2,dataY2);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
            if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";

            VMHL_Result += THQt_LatexShowTwoChartsOfLine (dataX,dataY1,dataY2,N,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, true);

            delete []dataX;
            delete []dataY1;
            delete []dataY2;
        }
        if (Type=="TwoIndependentLines")
        {
            int NX1=HQt_CountOfRowsFromQStringList(List,0);
            int NY1=HQt_CountOfRowsFromQStringList(List,1);
            int NX2=HQt_CountOfRowsFromQStringList(List,2);
            int NY2=HQt_CountOfRowsFromQStringList(List,3);
            double *dataX1=new double [NX1];
            double *dataY1=new double [NY1];
            double *dataX2=new double [NX2];
            double *dataY2=new double [NY2];

            THQt_ReadColFromQStringList(List,0,dataX1);
            THQt_ReadColFromQStringList(List,1,dataY1);
            THQt_ReadColFromQStringList(List,2,dataX2);
            THQt_ReadColFromQStringList(List,3,dataY2);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
            if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";

            VMHL_Result += THQt_LatexShowTwoIndependentChartsOfLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, true);

            delete []dataX1;
            delete []dataX2;
            delete []dataY1;
            delete []dataY2;
        }
        if (Type=="SeveralLines")
        {
            int N,M;

            M=HQt_CountOfColsFromQStringList(List);

            int *N_EveryCol=new int[M];

            N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

            double **X;
            X=new double*[N];
            for (int i=0;i<N;i++) X[i]=new double[M];

            THQt_ReadMatrixFromQStringList(List, X);

            if (ListNamesOfCharts.count()<M-1)
                for (int j=0;j<M-1-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

            QString *NameLine=new QString[M-1];
            for (int i=0;i<M-1;i++)NameLine[i]=ListNamesOfCharts.at(i);

            bool GrayStyle=false;
            if (ShowArea) GrayStyle=true;

            VMHL_Result += THQt_LatexShowChartsOfLineFromMatrix (X,N,M,Title,AxisX,AxisY,NameLine,"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, GrayStyle, false,false);

            for (int i=0;i<N;i++) delete [] X[i];
            delete [] X;
            delete [] N_EveryCol;
            delete [] NameLine;
        }
        if (Type=="SeveralIndependentLines")
        {
            int N,M;

            M=HQt_CountOfColsFromQStringList(List);

            int *N_EveryCol=new int[M];

            N=HQt_CountOfRowsFromQStringList(List,N_EveryCol);

            double **X;
            X=new double*[N];
            for (int i=0;i<N;i++) X[i]=new double[M];

            THQt_ReadMatrixFromQStringList(List, X);

            if (ListNamesOfCharts.count()<M/2)
                for (int j=0;j<M/2-ListNamesOfCharts.count();j++) ListNamesOfCharts << "";

            QString *NameLine=new QString[M/2];
            for (int i=0;i<M/2;i++)NameLine[i]=ListNamesOfCharts.at(i);

            bool GrayStyle=false;
            if (ShowArea) GrayStyle=true;

            VMHL_Result += THQt_LatexShowIndependentChartsOfLineFromMatrix (X,N_EveryCol,M, Title,AxisX,AxisY,NameLine,"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, GrayStyle, false,false);

            for (int i=0;i<N;i++) delete [] X[i];
            delete [] X;
            delete [] N_EveryCol;
            delete [] NameLine;
        }
        if (Type=="PointsAndLine")
        {
            int NX1=HQt_CountOfRowsFromQStringList(List,0);
            int NY1=HQt_CountOfRowsFromQStringList(List,1);
            int NX2=HQt_CountOfRowsFromQStringList(List,2);
            int NY2=HQt_CountOfRowsFromQStringList(List,3);
            double *dataX1=new double [NX1];
            double *dataY1=new double [NY1];
            double *dataX2=new double [NX2];
            double *dataY2=new double [NY2];

            THQt_ReadColFromQStringList(List,0,dataX1);
            THQt_ReadColFromQStringList(List,1,dataY1);
            THQt_ReadColFromQStringList(List,2,dataX2);
            THQt_ReadColFromQStringList(List,3,dataY2);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";
            if (ListNamesOfCharts.count()<2) ListNamesOfCharts << "";

            VMHL_Result += THQt_LatexShowTwoIndependentChartsOfPointsAndLine (dataX1,dataY1,NX1,dataX2,dataY2,NX2,Title,AxisX,AxisY,ListNamesOfCharts.at(0),ListNamesOfCharts.at(1),"Chart"+HQt_RandomString(8),ShowLine,ShowPoints,ShowArea,ShowSpecPoints, true, false);

            delete []dataX1;
            delete []dataX2;
            delete []dataY1;
            delete []dataY2;
        }
        if (Type=="Bar")
        {
            int N=HQt_CountOfRowsFromQStringList(List);
            double *data=new double [N];
            THQt_ReadVectorFromQStringList(List,data);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";

            VMHL_Result += THQt_LatexShowBar (data, N, Title, ListNamesOfCharts, AxisY, "Chart"+HQt_RandomString(8), true, MinZero);

            delete []data;
        }
        if (Type=="3DPoints")
        {
            int N=HQt_CountOfRowsFromQStringList(List,0);
            double *dataX=new double [N];
            double *dataY=new double [N];
            double *dataZ=new double [N];

            THQt_ReadColFromQStringList(List,0,dataX);
            THQt_ReadColFromQStringList(List,1,dataY);
            THQt_ReadColFromQStringList(List,2,dataZ);

            if (ListNamesOfCharts.count()<1) ListNamesOfCharts << "";

            VMHL_Result +=THQt_LatexShow3DPlotPoints (dataX, dataY, dataZ, N, Title, AxisX, AxisY, AxisZ, "Chart"+HQt_RandomString(8), "mathcad",true);

            delete []dataX;
            delete []dataY;
            delete []dataZ;
        }
    }
    catch(...)
    {
        VMHL_Result+=HQt_LatexShowAlert ("Неизвестная ошибка.");
        VMHL_Result="";
    }

    return VMHL_Result;
}
//---------------------------------------------------------------------------
