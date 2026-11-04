# Write your MySQL query statement below
select contest_id , round(count(distinct r.user_id)*100/(COUNT(distinct u.user_id) ),2) as percentage 
from  Register r, Users u 
GROUP BY r.contest_id
order by percentage desc, r.contest_id asc; 