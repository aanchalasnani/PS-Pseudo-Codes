Update operators : 

Examples :  $inc , $set , $unset

$ sign has multiple uses in mongodb
    -> precedes mql operators
    -> precedes aggregation pipelines stages //later on this course
    -> Allows access to field value






Comparision operators :
  
$eq = equal to         (it is a default operator which is always present even if we are not calling it)
$ne = not equal 
$gt = greater than      
$lt = less than 
$gte = Greater than or equal to 
$lte  = Less than or equal to 

Syntax to use this  : { <field> : { <operator> : <value> } }

// Inside Data Explorer 

    DB - sample_training 
    collection - trips

    {"tripduration" : { "$lte" : 60} } // here we searched for all the records whose tripduration 
    // is less than or equal to 60 .


    {"tripduration" : { "$lte" : 70} , "usertype" : { "$ne" : "subscriber" } }
    // here I searched for all the records where the tripdurations is less than or equal to 70
    // as well as the user is not a subscriber


// Equivalent commands in Mongo Shell are : 

    db.trip.find( {"tripduration" : { "$lte" : 60} } )
    db.trip.find( {"tripduration" : { "$lte" : 70} , "usertype" : { "$ne" : "subscriber" } } )








new topic : LOGIC operators ==>


$and : Match all of the specified query clauses  (this is used as an default operator when no operator is specified )
$or  : At least one of the query clauses is matched
$nor : Fail to match both given clauses
$not : Negates the query requirement

Syntax of $and , $or and $nor :

    { <operator> : [ {statement1}, {statement2},{statement3}, ...]}

Syntax of $not command is : 
    { $not : {statement}}

Using them in Data Explorer : 
    DB - sample_training , collection : inspections

    { $nor : [{"result" : "No Violation Issued"}, { "result" : "Violation Issued" } , {"result" : "Pass"} ]}  // this will give
    //all the records which will not include the result to be No Violation Issued , Violation Issued , Pass

Implicit AND  :-

    Find which student id is >25 and <100 in the sample_training.grades collection 

    we can specify a query like this:

        { $and : [ { "student_id" : { "$gt" : 25 }} , { "student_id" : { "$lt" : 100 }} ]}

    Better Option :

        { "student_id" : {"$gt" : 25 , "lt" : 100}}

Explicit AND :- 
    so we may think that when we have to explicit include and ?
    The answer is when you need to include the same operator more than once in a query

    For example : in route collection we might be interrestd to see how many CR2 and A81 airplanes come through the KZN airport ?

    { $or : [ { dst_airport : "KZN"  }  , {src_airport : "KZN" } ]}

    and 

    { $or : [{airplane : "CR2" }, {airplane : "A81" }]}


    Data Explorer : { $and : [ { $or : [ { "dst_airport" : "KZN"  }  , { "src_airport" : "KZN" } ]} , { $or : [{"airplane" : "CR2" }, {"airplane" : "A81" }]}] }

    Inside Mongo Shell : db.routes.find( { $and : [ { $or : [ { "dst_airport" : "KZN"  }  , { "src_airport" : "KZN" } ]} , { $or : [{"airplane" : "CR2" }, {"airplane" : "A81" }]}] } )








Expressive Query operator : 

    $expr allows the use of aggregation expressions within the query language

    $expr allows us to use the variables and conditions statements 

    { "$expr" : { "$eq" : [ "$start station id" , "$end station id" ] } }  // this will give us all the records in which
    // the start station id is equals to the end station id irrespective of their values

    $ denotes the use of operator
    $ addresses the field value


    In Mngo Shell : db.trips.find( { "$expr" : { "$eq" : [ "$start station id" , "$end station id" ] } } ).count()
                    db.trips.find( { "$expr" : { "$and": [ { "$gt": [ "$tripduration", 1200 ]} , { "$eq" : [ "$start station id" , "$end station id" ] } } ).count()
                    
MQL syntax : { <field> : { < operator > : <value> } }
Aggregation syntax : { <operator> : { <field> , <value> } }







Array operators : 

Projection Syntax : db.<collection>.find( { <query> } , { <Projection> } )
1 - include the field 
0 - not include the field
use only 1 or only 0

db.trips.find ( { "usertype" : "Subscriber" }, { "tripduration":1 , "gender" : 1 } ).pretty()

exception : when you want to exclude id field 1's and 0's will appear together in that query 

            example : db.<collection>.find ( { <query> } , { <field1> : 1  , "_id" : 0 })






