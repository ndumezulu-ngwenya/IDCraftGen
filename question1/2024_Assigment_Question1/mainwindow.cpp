// mainwindow.cpp
// Ndumezulu Mercy Ngwenya Student number: 18463339
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QChar>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    // Setup UI components
    ui->setupUi(this);
    // Connect the button click signal to generateID slot function
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::generateID);
}

MainWindow::~MainWindow() {
    // Destructor
    delete ui;
}

void MainWindow::generateID() {
    // Prompt the user to input full name
    QString fullName = QInputDialog::getText(this, "Enter Your Full Name", "Full Name:");
    if (fullName.isEmpty()) return;
    // Generate unique ID and initial key based on full name

    QString uniqueID = generateUniqueID(fullName);
    QString initialKey = generateInitialKey(fullName);

     // Display the generated ID and key
    QMessageBox::information(this, "Generated ID and Key", "Unique ID: " + uniqueID + "\nInitial Key: " + initialKey);
}

QString MainWindow::generateUniqueID(const QString& fullName) {

     // Split full name into parts
    QString mutableFullName = fullName;
    QStringList nameParts = mutableFullName.split(" ");
    // Generate initials
    QString initials;
    if (!nameParts.isEmpty()) {
        initials += nameParts.first().at(0).toUpper();
        if (nameParts.size() > 1)
            initials += nameParts[1].at(0).toUpper();
        else
            initials += nameParts.first().at(0).toUpper();
    }

    // Remove spaces from full name and get its length
    mutableFullName.remove(" ");
    QString count = QString::number(mutableFullName.length()).rightJustified(4, '0');
    return initials + count;
}

QString MainWindow::generateInitialKey(const QString& fullName) {
    // Generate initial key
    QString key;
    QStringList nameParts = fullName.split(" ");
    QString name = nameParts.join("").toLower();
    QStringList vowels;
    vowels << "a" << "e" << "i" << "o" << "u";
    QStringList consonants;
    consonants << "b" << "c" << "d" << "f" << "g" << "h" << "j" << "k" << "l" << "m" << "n" << "p" << "q" << "r" << "s" << "t" << "v" << "w" << "x" << "y" << "z";

    // Seed the random number generator with current time

    qsrand(QTime::currentTime().msec());

    // Flags to ensure at least one vowel and one consonant are selected
    bool hasVowel = false;
    bool hasConsonant = false;
    while (key.length() < 6) {
        int index = qrand() % name.length();
        QString character = QString(name.at(index));
        if (vowels.contains(character) && !hasVowel) {
            key += character;
            hasVowel = true;
        } else if (consonants.contains(character) && !hasConsonant) {
            key += character;
            hasConsonant = true;
        } else if (!key.contains(character)) {
            key += character;
        }
    }
    return key;
}
