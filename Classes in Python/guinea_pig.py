def is_fat(fat):
        if fat:
            return 'very'
        else:
            return 'not'
class Guinea_Pig():
    def __init__(self, name, fur, age, fat):
        self.name = name
        self.fur = fur
        self.age = age
        self.fat = fat
    def introduce(self):
        print(f"Hi, I am {self.name}.")
        print(f"I have {self.fur} fur.")
        print(f"I am {self.age} months old.")
        print(f"I am {is_fat(self.fat)} fat.\n")

puffy = Guinea_Pig("Puffy", "black and brown", 9, True)
fluffy = Guinea_Pig("Fluffy", "white", 11, False)

fluffy.introduce()
puffy.introduce()