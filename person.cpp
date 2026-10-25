Person::Person()
    : name_(""),
      phone_(""),
      person_address_(),
      person_credit_card_() {
}

Person::Person(std::string name, std::string phone,
               address person_address,
               credit_card person_credit_card)
    : name_(name),
      phone_(phone),
      person_address_(person_address),
      person_credit_card_(person_credit_card) {
}

void Person::name(std::string name) {
    name_ = name;
}

std::string Person::name() {
    return name_;
}

void Person::phone(std::string phone) {
    phone_ = phone;
}

std::string Person::phone() {
    return phone_;
}

void Person::person_address(address person_address) {
    person_address_ = person_address;
}

address Person::person_address() {
    return person_address_;
}

void Person::person_credit_card(credit_card person_credit_card) {
    person_credit_card_ = person_credit_card;
}

credit_card Person::person_credit_card() {
    return person_credit_card_;
}

std::string Person::person_info() {
    std::string info;

    info += "Name: " + name_ + "\n";
    info += "Phone: " + phone_ + "\n";
    info += "Address:\n";
    info += person_address_.address_info();
    info += "\nCredit Card:\n";
    info += person_credit_card_.credit_card_info();

    return info;
}

