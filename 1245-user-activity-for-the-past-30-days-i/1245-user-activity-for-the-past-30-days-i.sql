# Write your MySQL query statement below
-- select activity_date as day, count(distinct user_id) as active_users
-- from Activity
-- where activity_date >= date_sub("2019-07-27", interval 30 day)
-- and activity_date<= "2019-07-27"
-- group by activity_date
# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE activity_date BETWEEN '2019-06-28' AND '2019-07-27'
GROUP BY activity_date;

