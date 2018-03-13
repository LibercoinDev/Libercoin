#include "darksendconfig.h"
#include "ui_darksendconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "optionsmodel.h"
#include "walletmodel.h"
#include "init.h"

#include <QMessageBox>
#include <QPushButton>
#include <QKeyEvent>
#include <QSettings>

luxsendConfig::luxsendConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luxsendConfig),
    model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

luxsendConfig::~luxsendConfig()
{
    delete ui;
}

void luxsendConfig::setModel(WalletModel *model)
{
    this->model = model;
}

void luxsendConfig::clickBasic()
{
    configure(true, 10, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 10 * COIN));
    QMessageBox::information(this, tr("darksend Configuration"),
        tr(
            "darksend was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening Libercoin's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void luxsendConfig::clickHigh()
{
    configure(true, 10, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 10 * COIN));
    QMessageBox::information(this, tr("darksend Configuration"),
        tr(
            "darksend was successfully set to high (%1 and 8 rounds). You can change this at any time by opening Libercoin's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void luxsendConfig::clickMax()
{
    configure(true, 10, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 10 * COIN));
    QMessageBox::information(this, tr("darksend Configuration"),
        tr(
            "darksend was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening Bitcoin's configuration screen."
        ).arg(strAmount)
    );

    close();
}

void luxsendConfig::configure(bool enabled, int coins, int rounds) {

    QSettings settings;

    settings.setValue("nDarksendRounds", rounds);
    settings.setValue("nAnonymizeLibercoinAmount", coins);

    nDarksendRounds = rounds;
    nAnonymizeLibercoinAmount = coins;
}

