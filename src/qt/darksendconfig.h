#ifndef DARKSENDCONFIG_H
#define DARKSENDCONFIG_H

#include <QDialog>

namespace Ui {
    class luxsendConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class luxsendConfig : public QDialog
{
    Q_OBJECT

public:

    luxsendConfig(QWidget *parent = 0);
    ~luxsendConfig();

    void setModel(WalletModel *model);


private:
    Ui::luxsendConfig *ui;
    WalletModel *model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // DARKSENDCONFIG_H

