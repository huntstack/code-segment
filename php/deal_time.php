<?php

	/**
	* process date
	* @author huntstack
	* @time 2014-10-18
	*/
	class Process_Date{
		
		public $date;
		private $M,$D,$Y;

		/**
		* set the date for next operator
		* @parameter date:time string or timestamp
		*/
		function __construct($date=""){
			if($date == "" || empty($date)){
				$this->date = strtotime("now");
			}else if(gettype($date) == "string"){
				$this->date = strtotime($date);
			}else if(gettype($date) == "integer"){
				$this->date = $date;
			}else{
				throw new Exception("paramter must be timestamp or date string or empty for current time");
			}
			$this->M = date("m",$this->date);
			$this->D = date("d",$this->date);
			$this->Y = date("Y",$this->date);
		}


		public function get_last_day(){
			return strtotime("yesterday",$this->date);
		}

		public function get_next_day(){
			return strtotime("tomorrow",$this->date);
		}

		/**
		* get the specified weeks
		* @parameter $i:numbers of week
		* @parameter $flag:0->last,1->next
		*/
		public function get_week($i=0,$flag=1){
			if($flag == 0) return date("YW",strtotime("-$i week",$this->date));
			else if($flag == 1) return date("YW",strtotime("+$i week",$this->date));
		}

		/**
		* get the specified months
		* @parameter $i:numbers of month
		* @parameter $flag:0->last,1->next
		*/
		public function get_month($i=0,$flag=1){
			if($flag == 0) return date("Y-m",mktime(0,0,0, $this->M-$i, 1, $this->Y));
			else if($flag == 1) return date("Y-m",mktime(0,0,0, $this->M+$i, 1, $this->Y));
		}

		/**
		* get the specified days
		* @parameter $i:numbers of day
		* @parameter $flag:0->last,1->next
		*/
		public function get_day($i=0,$flag=1){
			if($flag == 0) return date("Y-m-d",mktime(0,0,0, $this->M, $this->D-$i, $this->Y));
			else if($flag == 1) return date("Y-m-d",mktime(0,0,0, $this->M, $this->D+$i, $this->Y));
		}

		/**
		* get the last $count days 
		* @parameter count:number
		*/
		public function get_last_days($count){
			$return  = array();
			for($i=1;$i<=$count;$i++){
				array_push($return, $this->get_day($i,0));
			}
			return $return;
		}

		/**
		* get the next $count days 
		* @parameter count:number
		*/
		public function get_next_days($count){
			$return  = array();
			for($i=1;$i<=$count;$i++){
				array_push($return, $this->get_day($i,1));
			}
			return $return;
		}

		/**
		* get the last $count weeks 
		* @parameter count:number
		*/
		public function get_last_weeks($count){
			$return  = array();
			for($i=1;$i<=$count;$i++){
				array_push($return, $this->get_week($i,0));
			}
			return $return;
		}

		/**
		* get the next $count weeks 
		* @parameter count:number
		*/
		public function get_next_weeks($count){
			$return  = array();
			for($i=1;$i<=$count;$i++){
				array_push($return, $this->get_week($i,1));
			}
			return $return;
		}

		/**
		* get the last $count months
		* @parameter count:number
		*/
		public function get_last_month($count){
			$return  = array();
			for($i=1;$i<=$count;$i++){
				array_push($return, $this->get_month($i,0));
			}
			return $return;
		}

		/**
		* get the next $count months
		* @parameter count:number
		*/
		public function get_next_month($count){
			$return  = array();
			for($i=1;$i<=$count;$i++){
				array_push($return, $this->get_month($i,1));
			}
			return $return;
		}

		/**
		* get the first day and the last day of a week
		*/
		public function get_week_begin_end(){
			$return["begin"] = mktime(0,0,0, $this->M, $this->D-date("w",$this->date)+1, $this->Y);
			$return["end"] = mktime(23,59,59, $this->M, $this->D-date("w",$this->date)+7, $this->Y);
			return $return;
		}

		/**
		* get the first day and the last day of a month
		*/
		public function get_month_begin_end(){
			$return["begin"] = strtotime("first day of",$this->date);
			$return["end"] = strtotime("last day of",$this->date);
			return $return;
		}
	}
?>