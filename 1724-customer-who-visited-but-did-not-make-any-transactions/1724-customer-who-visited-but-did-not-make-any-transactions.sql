# Write your MySQL query states
select customer_id, COUNT(customer_id) as count_no_trans
from Visits as v
left join Transactions as t
on v.visit_id = t.visit_id
where t.transaction_id is null
group by customer_id