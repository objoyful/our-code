#cSpell: disable
counties = ['Apache', 'Cochise', 'Coconino', 'Gila', 'Graham', 'Greenlee', 'La Paz',
            'Maricopa', 'Mohave', 'Pima', 'Pinal', 'Santa Cruz', 'Yavapai', 'Yuma']
cities = {
    'Apache': 'St. Johns',
    'Cochise': 'Bisbee',
    'Coconino': 'Flagstaff',
    'Gila': 'Globe',
    'Graham': 'Safford',
    'Greenlee': 'Clifton',
    'La Paz': 'Parker',
    'Maricopa': 'Phoenix',
    'Mohave': 'Holbrook',
    'Pima': 'Tucson',
    'Pinal': 'Florence',
    'Santa Cruz': 'Nogales',
    'Yavapai': 'Prescott',
    'Yuma': 'Yuma'
}

i = 0

while i <= len(counties) - 1:
    print(f"{counties[i]}'s county seat is {cities[counties[i]]}.")
    i += 1