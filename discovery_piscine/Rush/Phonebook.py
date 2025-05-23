#!/usr/bin/env python3

import re

class Phonebook:
    def __init__(self):
        self.phonebook = {}

    def add_contact(self):
        phone = self.check_input("phone number: ", "int")
        name = self.check_input ("name: ", "str")
        surname = self.check_input ("surname: ", "str")
        email = self.check_input ("email: ", "str", email=True)
        self.phonebook[phone] = {'name': name, 'surname': surname, 'email': email}

    def modify_contact(self):
        user_input = input("Please give me the phone number of the contact that you want to modify: ")
        contact = self.phonebook.get(user_input)
        if contact:
            input_to_modify = input("What do you want to modify ? (phone number, name, surname, email): ")
            if input_to_modify == "phone number":
                print ("You have to add a new contact, try not to make mistake :)\n But firts give me the old contact", end=" ")
                self.remove_contact()
                self.add_contact()
            elif input_to_modify == "name":
                contact['name'] = input("what do you want write ?:")
            elif input_to_modify == "surname":
                contact['surname'] = input("what do you want write ?:")
            elif input_to_modify == "email":
                contact['email'] = input("what do you want write ?:")

    def contact_list(self):
        if self.phonebook:
            for phone, value in self.phonebook.items():
                print({phone: value})
        else:
            print()

    def check_input(self, prompt, input_type, email=False):
        while True:
            value = input(prompt)
            if input_type == "int":
                if self.check_int(value):
                    return value
                else:
                    print("Your input is not correct, please try again!")
            elif input_type == "str":
                if self.check_str(value, email):
                    return value
                else:
                    print("Your input is not correct, please try again!")
             
    def check_int(self, value):
        try:
            int(value)
            return True
        except ValueError:
            return False
    
    def check_str(self, value, email=False):
        if email:
            return self.check_email(value)
        else:
            return value.isalpha()
        
    def check_email(self, value):
        return bool(re.search(r"^[a-zA-Z0-9._]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$", value))

    def remove_contact(self):
        phone = input("phone number: ")
        if phone in self.phonebook:
            del self.phonebook[phone]

phonebook = Phonebook()

while True:
    user_input = input("What do you want to do next (ADD, REMOVE, LIST, MODIFY, CLOSE): ")
    if user_input == "ADD":
        phonebook.add_contact()
    elif user_input == "LIST":
        phonebook.contact_list()
    elif user_input == "REMOVE":
        phonebook.remove_contact()
    elif user_input == "MODIFY":
        phonebook.modify_contact()
    elif user_input == "CLOSE":
        break

