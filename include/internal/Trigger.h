/* @@@LICENSE
*
*      Copyright (c) 2009-2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

#ifndef __ACTIVITYMANAGER_TRIGGER_H__
#define __ACTIVITYMANAGER_TRIGGER_H__

#include "Base.h"

class Activity;

class Trigger : public boost::enable_shared_from_this<Trigger>
{
public:
	Trigger();
	virtual ~Trigger();

	virtual void Arm(boost::shared_ptr<Activity> activity) = 0;
	virtual void Disarm(boost::shared_ptr<Activity> activity) = 0;

	virtual void Fire() = 0;

	virtual bool IsArmed(
		boost::shared_ptr<const Activity> activity) const = 0;
	virtual bool IsTriggered(
		boost::shared_ptr<const Activity> activity) const = 0;

	virtual MojErr ToJson(boost::shared_ptr<const Activity> activity,
		MojObject& rep, unsigned flags) const = 0;
};

#endif /* __ACTIVITYMANAGER_TRIGGER_H__ */
