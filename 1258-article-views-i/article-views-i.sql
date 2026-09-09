# Write your MySQL query statement below
select distinct v1.author_id as id from views v1 join views v2 on v1.article_id = v2.article_id where v1.author_id =v2.viewer_id order by v1.author_id 