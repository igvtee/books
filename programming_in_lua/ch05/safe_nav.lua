zip = company and company.director and
	company.director.address and 
	company.director.address.zipcode

E = {}
zip = (((company or E).directory or E).address or E).zipcode
