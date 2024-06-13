-- # Write your MySQL query statement below
select d.name as Department, e1.name as Employee, e1.salary as Salary
from Employee e1
inner join Department d
on e1.departmentId = d.id
where 3 > (
            select 
                count(distinct e2.salary)
            from 
                Employee e2
            where 
                e2.salary > e1.salary
                and
                e1.DepartmentId = e2.DepartmentId
)

-- select Department,Employee,Salary from
-- (select 
-- d.name as Department, 
-- e1.name as Employee, 
-- e1.salary as Salary,
-- dense_rank() over(partition by d.name order by e1.salary desc)) as Rank
-- from Employee e1
-- left join Department d
-- on e1.departmentId = d.id) temp where rank<=3