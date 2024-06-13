# Write your MySQL query statement below
select c.customer_id
from Customer c
join Product p
group by c.customer_id
having count(distinct p.product_key) = count(distinct c.product_key)

