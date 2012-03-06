#ifndef RULEINPUTWIDGET_H
#define RULEINPUTWIDGET_H

#include <QWidget>
#include <QString>
#include <QStringList>

class QLineEdit;
class QTextEdit;
class QLayout;
class QLabel;

/**
 * \brief Custom widget to edit or display NLP rule inputs
 */

class RuleInputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RuleInputWidget(QWidget *parent = 0);

    ~RuleInputWidget();

    void clear();

    QStringList inputList();

    void setInputList(const QStringList &inputList);

    void setFocusOnInput();

    void setFocusOnInputVariants();

    void installEventFilter(QObject *eventFilter);

    bool eventFilter(QObject *object, QEvent *event);

public slots:

    void clearHighlight();

    void highlightInput(int number);

signals:
    void inputTextEdited(const QString &);

private:
    QLayout   *m_layout;
    QLabel    *m_inputLabel;
    QLineEdit *m_input;
    QLabel    *m_inputVariantsLabel;
    QTextEdit *m_inputVariants;
    QObject   *m_eventFilter;
};

#endif // RULEINPUTWIDGET_H