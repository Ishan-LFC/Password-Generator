//GUI - Graphical User Interface

#include <QApplication>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QWidget>
#include <QtGlobal>
#include <QTime>
#include <QRandomGenerator>

//Generate Username
QString generateUserN(const QString& surname, const QString& firstName)
{
    QString username;

    // Add character from the first name to the username
    if(surname.length()>=4)
    {
        username = surname.left(4) + firstName.left(0);
    }

    // If the username is still less than 5 characters, add 0s to make it 5 characters long
    else
    {
        QString fullUserName = surname + firstName;
        username = fullUserName.leftJustified(5, '0');
    }

    //First letter upper case, rest lower case
    username[0] = username[0].toUpper();
    username += firstName.left(1).toLower();

    return username;
}

//Password Generator
QString genPassword(QString fullNameF)
{
    QString passWordF;
    for(int i = 0; i < 5; i++)
    {
        int j = rand()%(fullNameF.size() + 0);
        passWordF += fullNameF.at(j);

        //passWordF = QRandomGenerator::global()->bounded(fullNameF.size());

    }

    return passWordF;
}

//Main function
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString password;

    //password = "Error";

    QString surname = QInputDialog::getText(0, "Enter Surname", "Surname:");
    QString firstName = QInputDialog::getText(0, "Enter First Name", "First Name:");
    QString userName1 = generateUserN(surname, firstName);
    password = genPassword(firstName);
    QMessageBox::information(0, "User Credentials:", QString("Account Of: %1\nUsername: %2\nPassword: %3\n").arg(firstName).arg(userName1).arg(password));

    return 0;
}
