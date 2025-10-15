#include "../include/Card.h"

class AttackCard : public Card {
 protected:
  std::string attackType;

 public:
  AttackCard(std::string name, int power, std::string attackType);

  std::string getAttackType() const;
  void applyAttack(Tower& target) override;
};