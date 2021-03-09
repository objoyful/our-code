#cSpell: disable
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

for county in cities:
    print(f"{county}'s county seat is {cities[county]}.")