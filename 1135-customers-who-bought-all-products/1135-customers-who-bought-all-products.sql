# Write your MySQL query statement below
-- select c.customer_id
-- from Customer c
-- join Product p
-- group by c.customer_id
-- having count(distinct p.product_key) = count(distinct c.product_key)

select customer_id
from Customer
group by customer_id
having count(distinct product_key) = (
    select count(product_key) from Product
)
