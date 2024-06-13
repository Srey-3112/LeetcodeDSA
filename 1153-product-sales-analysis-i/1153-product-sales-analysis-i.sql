# Write your MySQL query statement below
select p.product_name, s.year, s.price 
from Sales as s
left join Product as p
on s.product_id = p.product_id

#instead of ON we can also use USING(product_id)